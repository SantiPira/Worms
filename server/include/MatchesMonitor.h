#pragma once

#include <mutex>
#include <unordered_map>
#include <vector>
#include "Game.h"

class MatchesMonitor {
private:
    //unordered_map<idGame, Game> Game is an object that contains the World and the players
    std::unordered_map<int, Game*> m_Games;
    std::mutex m_Mutex;
public:
    MatchesMonitor();
    int createGame(ProtectedQueue<std::string>* qClientUpdates);
    void removeGame(int id);
    std::vector<uint16_t> getAllPlayers();
    int getGames();
    void addPlayer(int id, ProtectedQueue<std::string>* qClientUpdates);
    ~MatchesMonitor() = default;
};