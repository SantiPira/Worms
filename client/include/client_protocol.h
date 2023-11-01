#ifndef CLIENT_PROTOCOL_H
#define CLIENT_PROTOCOL_H

#include "socket.h"

class ClientProtocol {
    private:
    Socket socket_cliente;
    bool socket_esta_cerrado{false};


    public:

    ClientProtocol(const char* ip, const char* puerto);




};





#endif