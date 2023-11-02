#include "client_juego.h"
#include "menuWindow.h"

Juego::Juego(const char* ip, const char* puerto) : comunicacion_con_server(ip, puerto) {}

void Juego::menu_window(){
    MenuWindow *menu = new MenuWindow();
    
    menu->show();
}

void Juego::createGame(std::string mapa, std::string nombre, std::string cantidad_jugadores) {


    std::cout<<"El mapa es: "<<mapa<<std::endl;
    std::cout<<"El nombre es: "<<nombre<<std::endl;
    std::cout<<"La cantidad de jugadores es: "<<cantidad_jugadores<<std::endl;

    std::cout << "Javier, hasta aca llegaste\n";
    ClientSender thread_emisor(this->comunicacion_con_server, mapa, nombre, cantidad_jugadores);
    thread_emisor.run();
    thread_emisor.join();

}

void Juego::iniciar_juego() {

    menu_window();

}