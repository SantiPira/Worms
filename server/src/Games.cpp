#include "../include/Games.h"

Games::Games() {}

int Games::addGame(int id) {
    std::lock_guard<std::mutex> lock(m_Mutex);
    m_Games.insert(std::make_pair(id, m_Games[id] + 1));
    return id;
}

void Games::removeGame(int id) {
    std::lock_guard<std::mutex> lock(m_Mutex);
    m_Games.erase(id);
}

int Games::createGame() {
    std::lock_guard<std::mutex> lock(m_Mutex);
    m_Games.insert(std::make_pair(m_Games.size(), 1));
    return m_Games.size() - 1;
}

int Games::getPlayers(int id) {
    std::lock_guard<std::mutex> lock(m_Mutex);
    return m_Games[id];
}

int Games::getGames() {
    std::lock_guard<std::mutex> lock(m_Mutex);
    return m_Games.size();
}

std::vector<uint16_t> Games::getAllPlayers() {
    std::lock_guard<std::mutex> lock(m_Mutex);
    std::vector<uint16_t> players;
    for (auto& game : m_Games) {
        players.push_back(game.second);
    }
    return players;
}

void Games::addPlayer(int id) {
    std::lock_guard<std::mutex> lock(m_Mutex);
    m_Games[id] += 1;
}
