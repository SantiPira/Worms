#include "../include/Game.h"


Game::Game(int id) : m_IdGame(id), m_InputActions(100), m_KeepRunning(true) {}

void Game::run() {
    int turnTime = MAX_TURN_SECONDS;
    int idStartPlayer = 0;
    std::string actionMessage;
    while (m_KeepRunning) {
        auto start_time = std::chrono::steady_clock::now();
        while (m_InputActions.try_pop(actionMessage)) {
            auto currentTime = std::chrono::steady_clock::now();
            auto elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(currentTime - start_time);
            if (elapsed_seconds.count() >= turnTime) {
                std::cout << "next turn" << std::endl;
                //push message to clients to start next turn
            } else {
                std::cout << "execute action" << std::endl;
            }
        }

        //process world state
    }
}

int Game::getPlayers() {
    return m_QClientUpdates.size();
}

int Game::addPlayer(ProtectedQueue<std::string> *qClientUpdates) {
    m_QClientUpdates.insert(std::make_pair(m_QClientUpdates.size(), qClientUpdates));
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

