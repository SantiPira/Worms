#pragma once

#include <mutex>
#include <unordered_map>
#include "Game.h"

class MatchesMonitor {
 private:
    std::mutex m_Mutex;
    std::unordered_map<int, Game*> m_Games;
 public:
    MatchesMonitor();
    int createGame(ProtectedQueue<std::string>* qClientUpdates);
    void removeGame(int id);
    std::vector<uint16_t> getAllPlayers();
    int getGames();
    void addPlayer(int id, ProtectedQueue<std::string>* qClientUpdates);
    ~MatchesMonitor() = default;
};