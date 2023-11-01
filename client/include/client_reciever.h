#ifndef CLIENT_RECIEVER_H
#define CLIENT_RECIEVER_H


#include "Thread.h"
#include "client_protocol.h"

class ClientReciever: public Thread {
    private:
    ClientProtocol &comunicacion_con_server;

    public:

    ClientReciever(ClientProtocol &protocolo_a_asginar);

    void run() override; 

    

};

#endif