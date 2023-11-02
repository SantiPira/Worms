#pragma once

#include <atomic>
#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>
#include <string>

#include "../../common_libs/include/ProtectedQueue.h"
#include "../../common_libs/include/Protocol.h"
#include "../../common_libs/include/Thread.h"
#include "../../common_libs/include/liberror.h"
#include "../../common_libs/include/socket.h"
#include "ClientSender.h"
#include "MatchesMonitor.h"
#include "messages/server/InitGameEnum.h"
#include "messages/server/from_client/ClientInitGame.h"


class Client : public Thread {
private:
    Protocol m_Protocol;
    std::atomic<bool> m_KeepRunning;
    MatchesMonitor* m_Matches;
    int idGame;
    int idPlayer;
    bool hasGame = false;
    ProtectedQueue<std::string> m_UpdatesGame;
    ProtectedQueue<std::string>* m_InputActions;
public:
    Client(Socket peer, MatchesMonitor* games);
    bool isDead();
    void stop();
    void kill();
    void run() override;

    ~Client() override = default;
    Client(const Client&) = delete;
    Client(Client&& other) = delete;
};
