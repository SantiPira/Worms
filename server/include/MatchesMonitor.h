#pragma once

#include <mutex>
#include <unordered_map>
#include "Game.h"
#include "messages/server/GameInfo.h"

class MatchesMonitor {
 private:
    std::mutex m_Mutex;
    std::unordered_map<int, Game*> m_Games;
 public:
    MatchesMonitor();
    int createGame(std::string gameName, std::string mapName, int players);
    void removeGame(int id);
    std::string getMapName(int idGame);
    std::vector<GameProperty> getGameProperties();
    int addPlayer(int id, ProtectedQueue<GameUpdate>* qClientUpdates);
    ProtectedQueue<std::string>* getInputActionGame(int idGame);
    ~MatchesMonitor() = default;

    void removePlayer(int idGame, int idPlayer);
};
