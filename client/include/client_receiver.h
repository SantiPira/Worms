#ifndef CLIENT_RECEIVER_H
#define CLIENT_RECEIVER_H

#include "../../common_libs/include/Thread.h"
#include "../../common_libs/include/Protocol.h"
#include "../../common_libs/include/ProtectedQueue.h"
#include "../../common_libs/include/messages/server/GameInfo.h"

#include <string>

class ClientReceiver: public Thread {
    private:
    Protocol& comunicacion_con_server;
    ProtectedQueue<std::string>& cola_de_mensajes;

    public:

    ClientReceiver(Protocol& protocolo_a_asignar, ProtectedQueue<std::string>& cola_a_asignar);

    void run() override;
};





#endif