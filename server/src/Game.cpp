#include "../include/Game.h"


Game::Game(int id) : m_IdGame(id), m_InputActions(100), m_KeepRunning(true) {}

void Game::run() {
    while (m_KeepRunning) {
        std::cout << "GameLoop" << std::endl;
    }
}

ProtectedQueue<std::string> *Game::getInputActions() {
    return &m_InputActions;
}

int Game::getPlayers() {
    return m_QClientUpdates.size();
}

void Game::addPlayer(ProtectedQueue<std::string> *qClientUpdates) {
    m_QClientUpdates.push_back(qClientUpdates);
    if (isReadyToStart()) {
        start();
    }
}

bool Game::isReadyToStart() {
    return m_QClientUpdates.size() == 2;
}
