#include "../include/Game.h"

#define POP_MESSAGE_QUANTITY 1
#define INVALID_USER_ACTION (-1)

Game::Game(int id, std::string gameName, std::string mapName, int players) : m_IdGame(id),
                                                                             m_GameName(std::move(gameName)), m_MapName(std::move(mapName)), m_Players(players), m_InputActions(100),
                                                                             m_KeepRunning(true), m_HasStarted(false), m_PopMessageQuantity(POP_MESSAGE_QUANTITY), world(m_MapName) {}

void Game::run() {
    setupWorld();
    std::vector<int> idPlayers;
    for (int i = 0; i < m_Players; i++) {
        idPlayers.push_back(i);
    }
    bool testMode = m_Players == 1;
    TurnHandler turnHandler(0, idPlayers, testMode);
    sendInfoTurns(0, turnHandler.getSecondsPerTurn(), GameAction::START_TURN);
    InstructionFactory instructionFactory;
    {
        bool getAll = true;
        auto updates = world.getWormsUpdates(getAll);
        pushUpdatesToClients(std::ref(updates));
    }

    world.step();
    allElementsIdle();

    while (m_KeepRunning) {
        processTurns(turnHandler, instructionFactory);
    }
}

void Game::processTurns(TurnHandler& turnHandler, InstructionFactory& instructionFactory) {
    try {
        while (turnHandler.isValidTurn()) {
            UserAction userAction;
            if (m_InputActions.try_pop(userAction) && userAction.getIdPlayer() == turnHandler.getCurrentPlayer()) {
                if (world.wormBrokeTurn(std::ref(userAction))) {
                    processAttackTurn(turnHandler, instructionFactory, userAction);
                    return;
                }
            }
            processNormalTurn(turnHandler, instructionFactory, std::ref(userAction));
        }
        finishTurn(turnHandler.getCurrentPlayer(), ActionType::NONE);
        allElementsIdle();
        startTurn(std::ref(turnHandler));
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
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        end_time = std::chrono::steady_clock::now();
        elapsed_seconds = end_time - start_time;
    }
}

int Game::getPlayers() const {
    return m_Players;
}

int Game::addPlayer(ProtectedQueue<GameUpdate> *qClientUpdates, std::string& playerName) {
    if(this->isReadyToStart()) {
        return -1;
    } else {
        m_QClientUpdates.insert(std::make_pair(m_QClientUpdates.size(), qClientUpdates));
        int idPlayer = m_QClientUpdates.size() - 1;
        m_PlayersInfo.insert(std::make_pair(idPlayer, std::ref(playerName)));
        if (isReadyToStart()) {
            m_HasStarted = true;
            start();
        }
        return idPlayer;
    }
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
        clientUpdate.second->push(std::ref(update));
    }
}

void Game::pushUpdatesToClients(std::reference_wrapper<std::vector<GameUpdate>> updates) {
    for (auto& clientQueue : m_QClientUpdates) {
        for (auto& update : updates.get()) {
            if(update.m_Movement != INVALID_ACTION) {
                clientQueue.second->push(std::ref(update));
            }
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
        world.SetWorm(clientId.first, m_PlayersInfo.at(clientId.first), randPosX, 11.0f);//cambiar por posicion random
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
    return m_QClientUpdates.size()-1 >= compare && m_KeepRunning.load();
}

void Game::sendInfoTurns(int playerId, double secondsPerTurn, GameAction infoTurn) {
    GameUpdate update{};
    update.m_TurnInfo = infoTurn;
    update.player_id = playerId;
    update.m_PlayerName = m_PlayersInfo.at(playerId);
    update.m_SecondsPerTurn = secondsPerTurn;
    pushUpdateToClients(std::ref(update));
}

bool Game::hasStarted() {
    return m_HasStarted;
}

void Game::finishTurn(int idCurrentPlayer, const ActionType& type) {
    sendInfoTurns(idCurrentPlayer, 0, GameAction::END_TURN);
    world.resetWormStatus(idCurrentPlayer, type);
    auto update = world.getWormUpdate(idCurrentPlayer, false);
    pushUpdateToClients(std::ref(update));
}

void Game::startTurn(TurnHandler& turnHandler) {
    turnHandler.nextTurn({});
    sendInfoTurns(turnHandler.getCurrentPlayer(), turnHandler.getSecondsPerTurn(), GameAction::START_TURN);
}

void Game::processAttackTurn(TurnHandler &turnHandler, InstructionFactory &instructionFactory, UserAction userAction) {
    finishTurn(turnHandler.getCurrentPlayer(), userAction.getAction());
    auto* attackInstruction = instructionFactory.createInstruction(userAction);
    world.execute(attackInstruction, userAction.getIdPlayer());
    delete attackInstruction;
    GameUpdate update;
    /*ANIMACION DE ATAQUE DEL WORM*/
    while (update.m_CurrentSprite != SPRITE_WACCUSE_IDLE) {
        update = world.getWormUpdate(turnHandler.getCurrentPlayer(), false);
        pushUpdateToClients(std::ref(update));
    }
    pushUpdateToClients(std::ref(update));
    /*TERMINA LA ANIMACION DEL ATAQUE DE WORM, Y YA SE ENVIO AL CLIENTE.*/
    world.resetWormStatus(turnHandler.getCurrentPlayer(), ActionType::NONE);
    update = world.getWormUpdate(turnHandler.getCurrentPlayer(), false);
    pushUpdateToClients(std::ref(update));
    world.step();
    allElementsIdle();
    std::vector<int> deadWormsIds;
    world.getDeadWormsIds(deadWormsIds);
    world.getDeathWormsUpdates(deadWormsIds); //estaria muerto
    size_t i = 0;
    while (i != deadWormsIds.size()) {
        auto updates = world.getWormsUpdates(false);
        for (auto& up : updates) {
            if (up.m_CurrentSprite == SPRITE_WACCUSE_GRAVE) {
                ++i;
            }
        }
        pushUpdatesToClients(std::ref(updates));
    }
    world.removeDeadWorms(deadWormsIds);
    turnHandler.nextTurn(std::ref(deadWormsIds));
    if (turnHandler.isEndGame()) {
        sendEndGame(turnHandler.getCurrentPlayer());
        m_KeepRunning = false;
        return;
    }
    sendInfoTurns(turnHandler.getCurrentPlayer(), turnHandler.getSecondsPerTurn(), GameAction::START_TURN);
}

void Game::allElementsIdle() {

    b2Body* projectile = world.getProjectile();
    GameUpdate projectileUpdate;

    while(!world.allElementsIDLE()) {
        auto updates = world.getWormsUpdates(false);

        if (projectile != nullptr) {
            projectileUpdate.player_id = 0xFE;
            projectileUpdate.x_pos = projectile->GetPosition().x;
            projectileUpdate.y_pos = projectile->GetPosition().y;
            projectileUpdate.m_Movement = GameAction::PROJECTILE_LAUNCHED;
            projectileUpdate.m_CurrentSprite = SpritesEnum::SPRITE_BAZOOKA_MISSILE;
            updates.push_back((projectileUpdate));
        }


        pushUpdatesToClients(std::ref(updates));
        waitFrameTime();
        world.step();
    }

}

void Game::processNormalTurn(TurnHandler &turnHandler, InstructionFactory &instructionFactory, UserAction &userAction) {
    if (userAction.getIdPlayer() != INVALID_USER_ACTION) {
        auto* instruction = instructionFactory.createInstruction(userAction);
        world.execute(instruction, userAction.getIdPlayer());
        delete instruction;
    }
    world.step();
    auto update = world.getWormUpdate(turnHandler.getCurrentPlayer(), false);
    if (update.m_Movement != INVALID_ACTION) {
        pushUpdateToClients(std::ref(update));
    }
    waitFrameTime();
    world.updateWormsMove();
}

void Game::sendEndGame(int winner) {
    GameUpdate update;
    update.m_TurnInfo = GameAction::END_GAME;
    update.player_id = winner;
    update.m_PlayerName = m_PlayersInfo.at(winner);
    pushUpdateToClients(std::ref(update));
}
