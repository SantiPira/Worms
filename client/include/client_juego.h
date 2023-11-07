#ifndef CLIENT_JUEGO_H
#define CLIENT_JUEGO_H
#include "../../common_libs/include/Protocol.h"
#include "../../common_libs/include/ProtectedQueue.h"
#include "client_sender.h"
#include "client_receiver.h"

#include <iostream>


class Juego{
    private:
    Protocol m_Protocol;
    ClientSender* emisor_de_mensajes{NULL};
    ClientReceiver* receptor_de_mensajes{NULL};
    bool inicio_el_juego{false};
    ProtectedQueue<std::string> cola_de_mensajes;

    public:

    explicit Juego(const std::string& ip, const std::string& puerto);

    void iniciar_juego();

    void joinGame();

    GameInfo getGamesInfo();

    void createGame(const std::string& mapa, const std::string& nombre, const std::string& cantidad_jugadores);

    void menu_window();


    Protocol *getProtocol();
};

#endif // CLIENT_JUEGO_H