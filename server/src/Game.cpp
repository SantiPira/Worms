#include "../include/Game.h"

#define POP_MESSAGE_QUANTITY 1

Game::Game(int id, std::string gameName, std::string mapName, int players) : m_IdGame(id),
    m_GameName(std::move(gameName)), m_MapName(std::move(mapName)), m_Players(players), m_InputActions(100),
    m_KeepRunning(true), m_PopMessageQuantity(POP_MESSAGE_QUANTITY), world(m_MapName),
    m_GameState(GameState::PLAYING) {}

void Game::run() {
    setupWorld();
    sendInfoTurns(0, GameAction::START_TURN);

    std::vector<int> idPlayers;
    for (int i = 0; i < m_Players; i++) {
        idPlayers.push_back(i);
    }

    TurnHandler turnHandler(0, idPlayers);
    InstructionFactory instructionFactory;
    {
        auto updates = world.getWormsUpdates(true);
        pushUpdatesToClients(std::ref(updates));
    }
    while (m_KeepRunning) {
        processTurns(turnHandler, instructionFactory);
        m_GameState = GameState::PLAYING;
    }
}

void Game::processTurns(TurnHandler& turnHandler, InstructionFactory& instructionFactory) {
    try {
        while (turnHandler.isValidTurn() || m_GameState == GameState::TURN_TRANSITION) {
            if (m_GameState == GameState::PLAYING) {
                std::vector<UserAction> userActions;
                std::vector<GameUpdate> updates;
                m_InputActions.try_pop(std::ref(userActions), m_PopMessageQuantity);
                if (userActions.empty()) {
                    userActions.emplace_back();
                }
                size_t idxInstruction = 0;
                if (processUserActions(userActions, updates, instructionFactory, idxInstruction)) {
                    m_GameState = GameState::TURN_TRANSITION;
                    processTransitionAction(userActions, instructionFactory, idxInstruction);
                    break;
                }
                pushSetToClients(std::ref(updates));
            } else if (m_GameState == GameState::TURN_TRANSITION) {
                // Aquí solo procesas las actualizaciones de daño a los Worms
                auto updates = world.getDamageUpdates();
                pushUpdatesToClients(std::ref(updates));
            }
            waitFrameTime();
        }
        endTurn(turnHandler);
    }  catch (const ClosedQueue& cqe) {
        //should do nothing, if queue has been closed this is the last iteration
    } catch (...) {
        std::cout << "Error in Game: " << this->m_IdGame << std::endl;
    }
}

bool Game::processUserActions(std::vector<UserAction>& userActions,
                              std::vector<GameUpdate>& updates,
                              InstructionFactory& instructionFactory, size_t& idxInstruction) {
    bool shouldChangeTurn = false;
    for (size_t i = 0; i < userActions.size(); i++) {
        if (userActions.at(i).getAction() == ActionType::ATTACK) {
            pushUpdateToClients(buildTransitionUpdate());
            shouldChangeTurn = true;
            idxInstruction = i;
            break;
        }
        auto* instruction = instructionFactory.createInstruction(userActions.at(i));
        world.execute(instruction, userActions.at(i).getIdPlayer());
        world.step();

        auto wormPositions = world.getWormsUpdates(false);
        for (auto& wormPosition : wormPositions) {
            updates.push_back(wormPosition);
        }
        delete instruction;
    }
    return shouldChangeTurn;
}

void Game::processTransitionAction(std::vector<UserAction> &userActions, InstructionFactory &instructionFactory,
                                   size_t &idxInstruction) {
    auto* instruction = instructionFactory.createInstruction(userActions.at(idxInstruction));
    world.execute(instruction, userActions.at(idxInstruction).getIdPlayer());
    world.step();
    auto updates = world.getWormsUpdates(false);
    pushUpdatesToClients(std::ref(updates));
    delete instruction;
}

void Game::waitFrameTime() {
    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end_time = start_time;
    std::chrono::duration<double> elapsed_seconds = end_time - start_time;
    double target_frame_time = 1.0 / 60.0;
    while (elapsed_seconds.count() < target_frame_time) {
        end_time = std::chrono::steady_clock::now();
        elapsed_seconds = end_time - start_time;
    }
}

void Game::endTurn(TurnHandler& turnHandler) {
    sendInfoTurns(turnHandler.getCurrentPlayer(), GameAction::END_TURN);
    world.resetWormStatus(turnHandler.getCurrentPlayer());
    std::vector<int> wormsRemovedIds;
    std::vector<GameUpdate> deadWorms;
    world.removeDeadWorms(std::ref(wormsRemovedIds));
    turnHandler.nextTurn(std::ref(wormsRemovedIds));
    sendInfoTurns(turnHandler.getCurrentPlayer(), GameAction::START_TURN);
}

int Game::getPlayers() const {
    return m_Players;
}

int Game::addPlayer(ProtectedQueue<GameUpdate> *qClientUpdates) {
    m_QClientUpdates.insert(std::make_pair(m_QClientUpdates.size(), qClientUpdates));
    if (isReadyToStart()) {
        start();
    }
    return m_QClientUpdates.size() - 1;
}

bool Game::isReadyToStart() {
    return static_cast<int>(m_QClientUpdates.size()) == m_Players;
}

ProtectedQueue<UserAction> *Game::getInputActions() {
    return &m_InputActions;
}

int Game::getIdGame() const {
    return m_IdGame;
}

std::string Game::getGameName() const {
    return m_GameName;
}

std::string Game::getMapName() const {
    return m_MapName;
}

void Game::pushUpdateToClients(GameUpdate &update) {
    for (auto& clientUpdate : m_QClientUpdates) {
        clientUpdate.second->try_push(std::ref(update));
    }
}

void Game::pushSetToClients(std::reference_wrapper<std::vector<GameUpdate>> updates) {
    for (auto& clientQueue : m_QClientUpdates) {
        for (auto& update : updates.get()) {
            clientQueue.second->try_push(std::ref(update));
        }
    }
}

void Game::pushUpdatesToClients(std::reference_wrapper<std::vector<GameUpdate>> updates) {
    for (auto& clientQueue : m_QClientUpdates) {
        for (auto& update : updates.get()) {
            clientQueue.second->try_push(std::ref(update));
        }
    }
}

std::unordered_map<int, ProtectedQueue<GameUpdate>*>* Game::getClientUpdates() {
    return &m_QClientUpdates;
}

void Game::setupWorld() {
    this->world.Setup();
    for (auto& clientId : m_QClientUpdates) {
        float randPosX = static_cast<float>(rand() % 20);
        world.SetWorm(clientId.first,randPosX, 11.0f);//cambiar por posicion random
    }
}

void Game::kill() {
    m_KeepRunning = false;
    m_InputActions.close();
    for (auto& clientUpdate : m_QClientUpdates) {
        clientUpdate.second->close();
    }
    m_QClientUpdates.clear();
}

bool Game::isStillPlayable() {
    unsigned long int compare;
    if( m_Players == 1) {
        compare = 1;
    } else {
        compare = 2;
    }
    return m_QClientUpdates.size()-1 >= compare;
}

void Game::sendInfoTurns(int playerId, GameAction infoTurn) {
    GameUpdate update{};
    update.m_SelfCondition = infoTurn;
    update.player_id = playerId;
    pushUpdateToClients(std::ref(update));
}

GameUpdate &Game::buildTransitionUpdate() {
    GameUpdate update{};
    update.m_SelfCondition = GameAction::TURN_TRANSITION;
    return std::ref(update);
}


