#include "../include/Game.h"


Game::Game(int id) : m_IdGame(id), m_InputActions(100), m_KeepRunning(true) {}

void Game::run() {
    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();

    // Espero hasta que pase 1/60 segundos
    std::chrono::steady_clock::time_point end_time = start_time;
    std::chrono::duration<double> elapsed_seconds = end_time - start_time;
    double target_frame_time = 1.0 / 60.0;  // 1/60 segundos
    while (elapsed_seconds.count() < target_frame_time) {
        end_time = std::chrono::steady_clock::now();
        elapsed_seconds = end_time - start_time;
    }
    while (m_KeepRunning) {
        std::cout << "GameLoop" << std::endl;
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

