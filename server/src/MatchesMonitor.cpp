#include <utility>

#include "../include/MatchesMonitor.h"

MatchesMonitor::MatchesMonitor() {}

void MatchesMonitor::removeGame(int id) {
    std::lock_guard<std::mutex> lock(m_Mutex);
    m_Games.erase(id);
}

int MatchesMonitor::createGame(std::string gameName, std::string mapName, int players) {
    std::lock_guard<std::mutex> lock(m_Mutex);
    int id = m_Games.size();
    Game* game = new Game(id, std::move(gameName), std::move(mapName), players);
    m_Games.insert(std::make_pair(id, game));
    return id;
}

int MatchesMonitor::addPlayer(int id, ProtectedQueue<GameUpdate>* qClientUpdates) {
    std::lock_guard<std::mutex> lock(m_Mutex);
    return m_Games.at(id)->addPlayer(qClientUpdates);
}

ProtectedQueue<UserAction> *MatchesMonitor::getInputActionGame(int idGame) {
    std::lock_guard<std::mutex> lock(m_Mutex);
    return m_Games.at(idGame)->getInputActions();
}

std::vector<GameProperty> MatchesMonitor::getGameProperties() {
    std::lock_guard<std::mutex> lock(m_Mutex);
    std::vector<GameProperty> gameProperties;
    for (auto& game : m_Games) {
        gameProperties.emplace_back(GameProperty{game.second->getIdGame(), game.second->getGameName(),
                                         game.second->getMapName(), game.second->getPlayers()});
    }
    return gameProperties;
}

std::string MatchesMonitor::getMapName(int idGame) {
    std::lock_guard<std::mutex> lock(m_Mutex);
    return m_Games.at(idGame)->getMapName();
}

void MatchesMonitor::removePlayer(int idGame, int idPlayer) {
    std::lock_guard<std::mutex> lock(m_Mutex);
    m_Games.at(idGame)->getClientUpdates()->erase(idPlayer);
    //TODO: Preguntar si no hay race condition aca.
}

