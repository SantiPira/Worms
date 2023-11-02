#ifndef CLIENT_JUEGO_H
#define CLIENT_JUEGO_H

#include <iostream>
#include "../../common_libs/include/Protocol.h"

class Juego{
    private:
    Protocol m_Protocol;
    //ClientProtocol protocolo_cliente;

    public:

    explicit Juego(const std::string& ip, const std::string& puerto);

    void iniciar_juego();

    void createGame(const std::string& mapa, const std::string& nombre, const std::string& cantidad_jugadores);

    void menu_window();


    Protocol *getProtocol();
};

#endif // CLIENT_JUEGO_H