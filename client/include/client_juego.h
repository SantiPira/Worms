#ifndef CLIENT_JUEGO_H
#define CLIENT_JUEGO_H

#include "client_sender.h"
#include "ProtectedQueue.h"

#include <iostream>

class Juego{
    private:
    ClientSender thread_emisor; 
    //cola de juan (muy profunda).

    public:

    Juego(const char* ip, const char* puerto);

    void iniciar_juego();

    void createGame(std::string mapa, std::string nombre, std::string cantidad_jugadores);

    void menu_window();


};

#endif // CLIENT_JUEGO_H