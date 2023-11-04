#ifndef CLIENT_SENDER_H
#define CLIENT_SENDER_H

#include "../../common_libs/include/Thread.h"
#include "../../common_libs/include/Protocol.h"
#include "../../common_libs/include/messages/server/GameInfo.h"

#include <string>

class ClientSender: public Thread{
    private:
    Protocol& comunicacion_con_server;
    GameInfo info_inicial;

    public:

    ClientSender(GameInfo info_de_juego, Protocol& protoclo_a_asignar);

    void run() override;

    

};



#endif