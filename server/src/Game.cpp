#include "../include/Game.h"

#define POP_MESSAGE_QUANTITY 1

Game::Game(int id, std::string gameName, std::string mapName, int players) : m_IdGame(id),
    m_GameName(std::move(gameName)), m_MapName(std::move(mapName)), m_Players(players), m_InputActions(100),
    m_KeepRunning(true), m_HasStarted(false), m_PopMessageQuantity(POP_MESSAGE_QUANTITY), world(m_MapName) {}

void Game::run() {
    setupWorld();
    std::vector<int> idPlayers;
    for (int i = 0; i < m_Players; i++) {
        idPlayers.push_back(i);
    }
    sendInfoTurns(0, GameAction::START_TURN);

    TurnHandler turnHandler(0, idPlayers);
    InstructionFactory instructionFactory;
    {
        bool getAll = true;
        auto updates = world.getWormsUpdates(getAll);
        pushUpdatesToClients(std::ref(updates));
    }

    while (m_KeepRunning) {
        processTurns(turnHandler, instructionFactory);
    }
}

void Game::processTurns(TurnHandler& turnHandler, InstructionFactory& instructionFactory) {
    try {
        while (turnHandler.isValidTurn()) {
            UserAction userAction;
            if (m_InputActions.try_pop(userAction) && userAction.getIdPlayer() == turnHandler.getCurrentPlayer()) {
                auto* instruction = instructionFactory.createInstruction(userAction);
                world.execute(instruction, userAction.getIdPlayer());
                delete instruction;
            }
            world.step();
            if (world.wormBrokeTurn(std::ref(userAction))) {
                break;
            }
            bool getAll = false;
            auto updates = world.getWormsUpdates(getAll);
            pushUpdatesToClients(std::ref(updates));
            waitFrameTime();
        }
        endTurn(turnHandler);
    }  catch (const ClosedQueue& cqe) {
    } catch (...) {
        std::cout << "Error in Game: " << this->m_IdGame << std::endl;
    }
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
    while (!world.isQuiet()) {
        world.step();
        bool getAll = false;
        auto updates = world.getWormsUpdates(getAll);
        pushUpdatesToClients(std::ref(updates));
        waitFrameTime();
    }
    world.resetWormStatus(turnHandler.getCurrentPlayer());
    std::vector<int> deadWorms;
    world.getDeadWormsIds(std::ref(deadWorms));
    if (!deadWorms.empty()) {
        while (world.wormsAlive(std::ref(deadWorms))) {
            world.step();
            bool getAll = false;
            auto updates = world.getWormsUpdates(getAll);
            pushUpdatesToClients(std::ref(updates));
            waitFrameTime();
        }
    }
    turnHandler.nextTurn(std::ref(deadWorms));
    world.removeDeadWorms(std::ref(deadWorms));
    sendInfoTurns(turnHandler.getCurrentPlayer(), GameAction::START_TURN);
}

int Game::getPlayers() const {
    return m_Players;
}

int Game::addPlayer(ProtectedQueue<GameUpdate> *qClientUpdates) {
    m_QClientUpdates.insert(std::make_pair(m_QClientUpdates.size(), qClientUpdates));
    if (isReadyToStart()) {
        m_HasStarted = true;
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

bool Game::hasStarted() {
    return m_HasStarted;
}
