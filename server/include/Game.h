#pragma once

#include "../../common_libs/include/Thread.h"
#include "Client.h"

/*GameLoop gameLogic*/
class Game : public Thread {
 private:
    int m_IdGame;
    std::vector<ProtectedQueue<std::string>*> m_QClientUpdates; //TODO: Change string to GameUpdate later
    ProtectedQueue<std::string> m_InputActions;
    std::atomic<bool> m_KeepRunning;
public:
    explicit Game(int id);
    void run() override;
    ProtectedQueue<std::string>* getInputActions();
    int getPlayers();
    void addPlayer(ProtectedQueue<std::string>* qClientUpdates);
    void stop();
    ~Game() override = default;
    Game(const Game&) = delete;
    Game(Game&& other) = delete;

    bool isReadyToStart();
};