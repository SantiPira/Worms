#include "../include/MatchesMonitor.h"

MatchesMonitor::MatchesMonitor() {}

void MatchesMonitor::removeGame(int id) {
    std::lock_guard<std::mutex> lock(m_Mutex);
    m_Games.erase(id);
}

int MatchesMonitor::createGame() {
    std::lock_guard<std::mutex> lock(m_Mutex);
    int id = m_Games.size();
    Game* game = new Game(id);
    m_Games.insert(std::make_pair(id, game));
    return id;
}

int MatchesMonitor::getGames() {
    std::lock_guard<std::mutex> lock(m_Mutex);
    return m_Games.size();
}

std::vector<uint16_t> MatchesMonitor::getAllPlayers() {
    std::lock_guard<std::mutex> lock(m_Mutex);
    std::vector<uint16_t> players;
    for (auto& game : m_Games) {
        players.push_back(game.second->getPlayers());
    }
    return players;
}

int MatchesMonitor::addPlayer(int id, ProtectedQueue<std::string>* qClientUpdates) {
    std::lock_guard<std::mutex> lock(m_Mutex);
    return m_Games.at(id)->addPlayer(qClientUpdates);
}

Game *MatchesMonitor::getGame(int idGame) {
    std::lock_guard<std::mutex> lock(m_Mutex);
    return m_Games.at(idGame);
}

ProtectedQueue<std::string> *MatchesMonitor::getInputActionGame(int idGame) {
    std::lock_guard<std::mutex> lock(m_Mutex);
    return m_Games.at(idGame)->getInputActions();
}

