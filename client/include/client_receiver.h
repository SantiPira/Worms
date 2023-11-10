#ifndef CLIENT_RECEIVER_H
#define CLIENT_RECEIVER_H

#include "../../common_libs/include/Thread.h"
#include "../../common_libs/include/Protocol.h"
#include "../../common_libs/include/ProtectedQueue.h"
#include "../../common_libs/include/messages/server/GameInfo.h"
#include <string>

class ClientReceiver: public Thread {
 private:
    Protocol& m_Protocol;
    ProtectedQueue<GameUpdate>& m_GameUpdates;

 public:
    ClientReceiver(Protocol& protocol, ProtectedQueue<GameUpdate>& gameUpdates);

    void run() override;
};

#endif