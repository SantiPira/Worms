#pragma once

#include "Protocol.h"
#include "ProtectedQueue.h"
#include "GameClient.h"
#include "waitingWindow.h"

class ClientManager {
 private:
    Protocol* m_Protocol;
    int m_IdPlayer;
    int m_CantPlayers;
    GameClient m_Game{};
    ProtectedQueue<std::string> settingsQueue;
    ProtectedQueue<GameUpdate> gameUpdates;
    bool m_KeepRunning;
    WaitingWindow* m_WaitingWindow;

 public:
    ClientManager(Protocol* protocol, int idPlayer, int cantPlayers, WaitingWindow* waitingWindow);
    void init();
    void gameLoop();
    ~ClientManager() = default;
    ClientManager(const ClientManager&) = delete;
    ClientManager(ClientManager&&) = delete;
};