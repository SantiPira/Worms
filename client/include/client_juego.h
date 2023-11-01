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

    void createGame(std::string mapa, std::string nombre, std::string cantidad_jugadores);

    void menu_window();


};

#endif // CLIENT_JUEGO_H