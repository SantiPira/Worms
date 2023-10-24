#pragma once

#include <mutex>
#include <unordered_map>
#include <vector>

class Games {
private:
    std::unordered_map<int, int> m_Games;
    std::mutex m_Mutex;
public:
    Games();
    int createGame();
    int addGame(int id);
    void removeGame(int id);
    int getPlayers(int id);
    std::vector<uint16_t> getAllPlayers();
    int getGames();
    void addPlayer(int id);
    ~Games() = default;
};