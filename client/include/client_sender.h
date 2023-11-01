#ifndef CLIENT_SENDER_H
#define CLIENT_SENDER_H

#include "Thread.h"
#include "client_protocol.h"
#include "client_reciever.h"

class ClientSender: public Thread {
    private:
    ClientProtocol comunicacion_con_server;

    public:

    ClientSender(const char* ip, const char* puerto);

    void run() override; 

};




#endif