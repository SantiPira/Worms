#include "client_juego.h"
#include "menuWindow.h"

Juego::Juego(const char* ip, const char* puerto) : ip(ip), puerto(puerto), m_Protocol(ip, puerto){}

void Juego::menu_window(){
    MenuWindow *menu = new MenuWindow();
    
    menu->show();
}

void Juego::createGame(std::string mapa, std::string nombre, std::string cantidad_jugadores) {
    std::cout<<"El mapa es: "<<mapa<<std::endl;
    std::cout<<"El nombre es: "<<nombre<<std::endl;
    std::cout<<"La cantidad de jugadores es: "<<cantidad_jugadores<<std::endl;
    this->m_Protocol.sendClientInitGame(std::ref(mapa), std::ref(nombre), std::ref(cantidad_jugadores));
}

void Juego::iniciar_juego() {

    //ventana de juego
    std::cout<<"El ip es: "<<ip<<std::endl;
    std::cout<<"El puerto es: "<<puerto<<std::endl;
    menu_window();

}