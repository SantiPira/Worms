#pragma once

#include <atomic>
#include <unordered_map>
#include "../../common_libs/include/Thread.h"
#include "../../common_libs/include/ProtectedQueue.h"

/*GameLoop gameLogic*/
class Game : public Thread {
 private:
    int m_IdGame;
    std::unordered_map<int, ProtectedQueue<std::string>*> m_QClientUpdates; //TODO: Change string to GameUpdate later
    ProtectedQueue<std::string> m_InputActions;
    std::atomic<bool> m_KeepRunning;
public:
    explicit Game(int id);
    void run() override;
    int getPlayers();
    int addPlayer(ProtectedQueue<std::string>* qClientUpdates);
    ProtectedQueue<std::string>* getInputActions();
    void stop();
    ~Game() override = default;
    Game(const Game&) = delete;
    Game(Game&& other) = delete;

    bool isReadyToStart();
};