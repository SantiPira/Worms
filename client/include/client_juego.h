#ifndef CLIENT_JUEGO_H
#define CLIENT_JUEGO_H

#include <iostream>

class Juego{
    private:
    std::string ip;
    std::string puerto;
    //ClientProtocol protocolo_cliente;

    public:

    Juego(const char* ip, const char* puerto);

    void iniciar_juego();

    void game_window();


};

#endif // CLIENT_JUEGO_H