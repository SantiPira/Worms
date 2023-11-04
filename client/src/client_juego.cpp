#include "client_juego.h"
#include "menuWindow.h"




GameInfo Juego::getGamesInfo(){

    //GameProperty gameProperty(0, "", "", 0);
    //GameInfo gameInfo(InitGameEnum::JOIN_GAME, {gameProperty});

    GameInfo info_de_juego;   
    info_de_juego.setIdAction(InitGameEnum::LIST_GAMES);

    //this->m_Protocol.sendGameInfo(info_de_juego);

    this->emisor_de_mensajes = new ClientSender(info_de_juego, this->m_Protocol);
    this->emisor_de_mensajes->start();

    GameInfo serverResponse = this->m_Protocol.recvGameInfo();

    this->receptor_de_mensajes = new ClientReceiver(this->m_Protocol, this->cola_de_mensajes);
    this->receptor_de_mensajes->start();


    return serverResponse;
}



Juego::Juego(const std::string& ip, const std::string& puerto) : 
m_Protocol(ip, puerto), cola_de_mensajes(100) {}

void Juego::menu_window(){
    MenuWindow *menu = new MenuWindow(nullptr, this);
    
    menu->show();
}

void Juego::createGame(const std::string& mapa, const std::string& nombre, const std::string& cantidad_jugadores) {
    
    GameProperty gameProperty(0, nombre, mapa, std::stoi(cantidad_jugadores));
    GameInfo gameInfo(InitGameEnum::CREATE_GAME, {gameProperty});

    this->emisor_de_mensajes = new ClientSender(gameInfo, this->m_Protocol);
    this->emisor_de_mensajes->start();
 
    std::cout<<"El mapa es: "<<mapa<<std::endl;
    std::cout<<"El nombre es: "<<nombre<<std::endl;
    std::cout<<"La cantidad de jugadores es: "<<cantidad_jugadores<<std::endl;

    this->receptor_de_mensajes = new ClientReceiver(this->m_Protocol, this->cola_de_mensajes);
    this->receptor_de_mensajes->start();

}

void Juego::joinGame() {



}


void Juego::iniciar_juego() {

    //ventana de juego
    //std::cout<<"El ip es: "<<ip<<std::endl;
    //std::cout<<"El puerto es: "<<puerto<<std::endl;
    menu_window();

    //this->emisor_de_mensajes->join();
}

Protocol *Juego::getProtocol() {
    return &m_Protocol;
}
