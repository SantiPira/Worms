#pragma once

#include <atomic>
#include <unordered_map>
#include "../../common_libs/include/Thread.h"
#include "../../common_libs/include/ProtectedQueue.h"

#define MAX_TURN_SECONDS 120
/*GameLoop gameLogic*/
class Game : public Thread {
 private:
    int m_IdGame;
    std::string m_GameName;
    std::string m_MapName;
    int players{};
    std::unordered_map<int, ProtectedQueue<std::string>*> m_QClientUpdates; //TODO: Change string to GameUpdate later
    ProtectedQueue<std::string> m_InputActions;
    std::atomic<bool> m_KeepRunning;
public:
    explicit Game(int id, std::string gameName, std::string mapName);
    void run() override;
    //getters
    int getIdGame() const;
    std::string getGameName() const;
    std::string getMapName() const;
    int getPlayers();
    int addPlayer(ProtectedQueue<std::string>* qClientUpdates);
    ProtectedQueue<std::string>* getInputActions();
    void stop();
    ~Game() override = default;
    Game(const Game&) = delete;
    Game(Game&& other) = delete;

    bool isReadyToStart();
};