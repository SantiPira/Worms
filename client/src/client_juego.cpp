#include "client_juego.h"
#include "menuWindow.h"

Juego::Juego(const char* ip, const char* puerto) : ip(ip), puerto(puerto){}

void Juego::game_window(){
    MenuWindow *menu = new MenuWindow();
    
    menu->show();
}

void Juego::iniciar_juego() {

    //ventana de juego
    std::cout<<"El ip es: "<<ip<<std::endl;
    std::cout<<"El puerto es: "<<puerto<<std::endl;

    game_window();

}