#ifndef CLIENT_SENDER_H
#define CLIENT_SENDER_H

#include <SDL_events.h>
#include <iostream>
#include <string>
#include <atomic>
#include "../../common_libs/include/Thread.h"
#include "../../common_libs/include/Protocol.h"
#include "../../common_libs/include/messages/server/GameInfo.h"
#include "../../common_libs/include/messages/user_actions/UserAction.h"
#include "ProtectedQueue.h"

class EventSender : public Thread {
 private:
    Protocol& m_Protocol;
    std::atomic<bool> m_IsMyTurn;
    std::atomic<bool> m_KeepRunning;
    int m_IdPlayer;
    ProtectedQueue<std::string>& m_SettingsQueue;
    
 public:
    EventSender(Protocol& protocol, int idPlayer, ProtectedQueue<std::string>& settingsQueue, bool isMyTurn);
    void run() override;
    bool isRunning();
    void stop();

    void setItsMyTurn(bool isMyTurn);
};

#endif