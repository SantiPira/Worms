#include <utility>

#include "../include/Game.h"


Game::Game(int id, std::string gameName, std::string mapName) : m_IdGame(id), m_GameName(std::move(gameName)),
    m_MapName(std::move(mapName)), m_InputActions(100), m_KeepRunning(true) {}

void Game::run() {
    int turnTime = MAX_TURN_SECONDS;
    int idCurrentPlayer, idPreviousPlayer = 0;
    std::string actionMessage;
    auto startTime = std::chrono::steady_clock::now();
    while (m_KeepRunning) {
        while (m_InputActions.try_pop(actionMessage)) {
            auto currentTime = std::chrono::steady_clock::now();
            auto elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);
            if (elapsed_seconds.count() >= turnTime) {
                startTime = currentTime;
                ++idCurrentPlayer;
                //A problem could be if a turn ends and this message is sent before a world state.
                break;
            }
            std::cout << "execute action" << std::endl;
        }
        //process world state
        //when world state is processed check if the turn is over, and only then send the message to start the next turn
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);
        if (elapsed_seconds.count() >= turnTime || idCurrentPlayer != idPreviousPlayer) {
            startTime = currentTime;
            ++idCurrentPlayer;
            std::cout << "push message to clients to start next turn" << std::endl;
        }

    }
}

int Game::getPlayers() {
    return m_QClientUpdates.size();
}

int Game::addPlayer(ProtectedQueue<std::string> *qClientUpdates) {
    m_QClientUpdates.insert(std::make_pair(m_QClientUpdates.size(), qClientUpdates));
    players++;
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



