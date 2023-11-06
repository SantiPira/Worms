#pragma once

#include <atomic>
#include <iostream>

#include "../../common_libs/include/ProtectedQueue.h"
#include "../../common_libs/include/Protocol.h"
#include "../../common_libs/include/Thread.h"

class ClientSender : public Thread {
private:
    Protocol& m_Protocol;
    ProtectedQueue<std::string>* m_SelfQueue;
    int idPlayer;
    std::atomic<bool> m_KeepRunning;
 public:
    ClientSender(Protocol& protocol, ProtectedQueue<std::string>* selfQueue, int idPlayer);
    virtual void run() override;
    void stop();
    ~ClientSender() override = default;
    ClientSender(const ClientSender&) = delete;
    ClientSender(ClientSender&& other) = delete;
};
