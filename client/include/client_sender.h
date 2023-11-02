#ifndef CLIENT_SENDER_H
#define CLIENT_SENDER_H

#include "Thread.h"
#include "client_protocol.h"
#include "client_reciever.h"

#include <string>


class ClientSender: public Thread {
    private:
    ClientProtocol &comunicacion_con_server;
    
    bool se_creo_partida_nueva{false};
    std::string nombre_mapa;
    std::string nombre_partida;
    std::string cantidad_jugadores;
   
    public:

    ClientSender(ClientProtocol &protocolo_a_asignar, std::string nombre_mapa, 
    std::string nombre_partida, std::string cantidad_jugadores);

    ClientSender(ClientProtocol &protocolo_a_asignar);

    void run() override; 

};




#endif //CLIENT_SENDER_H