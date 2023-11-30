#include <utility>

#include "../include/MatchesMonitor.h"

MatchesMonitor::MatchesMonitor() {}

void MatchesMonitor::removeGame(int id) {
    // this lock is commented as this method is used as private
    //std::lock_guard<std::mutex> lock(m_Mutex);
    Game * gameToRemove = m_Games.at(id);
    if(! gameToRemove->hasStarted()) {
        m_Games.at(id)->start();
    }
    m_Games.at(id)->kill();
    m_Games.at(id)->join();
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
        if(!game.second->isReadyToStart()) {
            gameProperties.emplace_back(game.second->getIdGame(), game.second->getGameName(),
                                             game.second->getMapName(),
                                             static_cast<int>(game.second->getClientUpdates()->size()),
                                             game.second->getPlayers());
        }
    }
    return gameProperties;
}

std::string MatchesMonitor::getMapName(int idGame) {
    std::lock_guard<std::mutex> lock(m_Mutex);
    return m_Games.at(idGame)->getMapName();
}

void MatchesMonitor::removePlayer(int idGame, int idPlayer) {
    std::lock_guard<std::mutex> lock(m_Mutex);
    if(m_Games.count(idGame) > 0) {
        if(! m_Games.at(idGame)->isStillPlayable()) {
            removeGame(idGame);
        } else {
            m_Games.at(idGame)->getClientUpdates()->erase(idPlayer);
        }
    }
    //TODO: Preguntar si no hay race condition aca.
}

