#include "../include/Game.h"

#define POP_MESSAGE_QUANTITY 1

Game::Game(int id, std::string gameName, std::string mapName, int players) : m_IdGame(id), m_GameName(std::move(gameName)),
    m_MapName(std::move(mapName)), m_Players(players), m_InputActions(100), m_KeepRunning(true),
    m_PopMessageQuantity(POP_MESSAGE_QUANTITY), world(m_MapName) {}

void Game::run() {
    setupWorld();
    sendInfoTurns(0, GameAction::START_TURN);

    std::vector<int> idPlayers;
    for (int i = 0; i < m_Players; i++) {
        idPlayers.push_back(i);
    }

    TurnHandler turnHandler(0, idPlayers);
    {
        auto update = world.getWormsUpdates();
        pushUpdatesToClients(std::ref(update));
    }
    InstructionFactory instructionFactory;
    while (m_KeepRunning) {
        bool shouldChangeTurn = false;
        try {
            while (turnHandler.isValidTurn()) {
                std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();

                std::vector<UserAction> userActions;
                std::unordered_set<GameUpdate, GameUpdateHash> updates;
                m_InputActions.try_pop(std::ref(userActions), m_PopMessageQuantity);
                if (userActions.empty()) {
                    userActions.emplace_back();
                }
                for (auto& userAction : userActions) {
                    if (userAction.getAction() == ActionType::ATTACK) {
                        pushUpdateToClients(buildTransitionUpdate());
                        shouldChangeTurn = true;
                        break;
                    }
                    auto* instruction = instructionFactory.createInstruction(userAction);
                    world.execute(instruction, userAction.getIdPlayer());
                    world.step();

                    auto wormPositions = world.getWormsUpdates();
                    for (auto& wormPosition : wormPositions) {
                        updates.insert(wormPosition);
                    }
                    delete instruction;
                }
                if (shouldChangeTurn) {
                    auto* instruction = instructionFactory.createInstruction(userActions.at(0));
                    world.execute(instruction, userActions.at(0).getIdPlayer());
                    world.step();
                    break;
                }
                pushSetToClients(std::ref(updates));

                std::chrono::steady_clock::time_point end_time = start_time;
                std::chrono::duration<double> elapsed_seconds = end_time - start_time;
                double target_frame_time = 1.0 / 60.0;
                while (elapsed_seconds.count() < target_frame_time) {
                    end_time = std::chrono::steady_clock::now();
                    elapsed_seconds = end_time - start_time;
                }
            }
            sendInfoTurns(turnHandler.getCurrentPlayer(), GameAction::END_TURN);
            world.resetWormStatus(turnHandler.getCurrentPlayer());
            std::vector<int> wormsRemovedIds;
            std::vector<GameUpdate> deadWorms;
            world.removeDeadWorms(std::ref(wormsRemovedIds));
            turnHandler.nextTurn(std::ref(wormsRemovedIds));
            sendInfoTurns(turnHandler.getCurrentPlayer(), GameAction::START_TURN);
        }  catch (const ClosedQueue& cqe) {
            //should do nothing, if queue has been closed this is the last iteration
        } catch (...) {
            std::cout << "Error in Game: " << this->m_IdGame << std::endl;
        }
    }
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

void Game::pushSetToClients(std::reference_wrapper<std::unordered_set<GameUpdate, GameUpdateHash>> updates) {
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
