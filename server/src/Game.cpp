#include "../include/Game.h"

#define POP_MESSAGE_QUANTITY 1

Game::Game(int id, std::string gameName, std::string mapName) : m_IdGame(id), m_GameName(std::move(gameName)),
    m_MapName(std::move(mapName)), m_InputActions(100), m_KeepRunning(true), m_PopMessageQuantity(POP_MESSAGE_QUANTITY), world(m_MapName) {}

void Game::run() {
    //std::vector<std::string> updates;
    setupWorld();
    GameUpdate update;
    update.action = TURN_INFO;
    update.player_id = 1;
    pushUpdateToClients(std::ref(update));
    TurnHandler turnHandler(1, m_Players);
    while (m_KeepRunning) {
        while (turnHandler.isValidTurn()) {
            //Ver como se estan almacenando los mensajes en el vector, si hay repetidos etc... y como llega al pushUpdateToClients..
            //m_InputActions.try_pop(std::ref(updates), m_PopMessageQuantity);
            std::string client_action;
            m_InputActions.try_pop(std::ref(client_action));
            GameUpdate update = world.UpdateWorld();
            pushUpdateToClients(std::ref(update));
            //TODO: Revisar esto, pero creo que deberia estar bien, el loop del turnHandler no esta mal, ya que administra de quien es el turno.
            std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
            // Espero hasta que pase 1/60 segundos
            std::chrono::steady_clock::time_point end_time = start_time;
            std::chrono::duration<double> elapsed_seconds = end_time - start_time;
            double target_frame_time = 1.0 / 60.0;  // 1/60 segundos
            while (elapsed_seconds.count() < target_frame_time) {
                end_time = std::chrono::steady_clock::now();
                elapsed_seconds = end_time - start_time;
            }
        }
        turnHandler.nextTurn();
        GameUpdate update;
        update.action = TURN_INFO;
        update.player_id = turnHandler.getCurrentPlayer();
        pushUpdateToClients(std::ref(update));
    }
}

int Game::getPlayers() {
    return m_QClientUpdates.size();
}

int Game::addPlayer(ProtectedQueue<GameUpdate> *qClientUpdates) {
    m_QClientUpdates.insert(std::make_pair(m_QClientUpdates.size(), qClientUpdates));
    m_Players++;
    if (isReadyToStart()) {
        start();
    }
    return m_QClientUpdates.size() - 1;
}

bool Game::isReadyToStart() {
    return m_QClientUpdates.size() == 2;
}

ProtectedQueue<std::string> *Game::getInputActions() {
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
            clientQueue.second->push(std::ref(update));
        }
    }
}

std::unordered_map<int, ProtectedQueue<GameUpdate>*>* Game::getClientUpdates() {
    return &m_QClientUpdates;
}

void Game::setupWorld() {
    this->world.Setup();
    for (auto& clientId : m_QClientUpdates) {
        world.SetWorm(clientId.first,5.0f, 10.0f);//cambiar por posicion random
    }    
}

void Game::updateWorld() {
    world.UpdateWorld();
}
