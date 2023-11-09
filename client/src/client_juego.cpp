#include "client_juego.h"
#include "menuWindow.h"

GameInfo Juego::getGamesInfo(){

    GameInfo actualGameInfo;
    actualGameInfo.setIdAction(InitGameEnum::LIST_GAMES);
        
    this->m_Protocol.sendGameInfo(actualGameInfo);

    GameInfo serverResponse = this->m_Protocol.recvGameInfo();

    //this->map_info = this->m_Protocol.recvMap();

    //std::cout << "RECIBIR EL MAPA";

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
    m_Protocol.sendGameInfo(std::ref(gameInfo));
    
    //this->map_info = this->m_Protocol.recvMap();
    //std::cout << "RECIBIR EL MAPA";

    this->game_renderer = new ClientRenderer(this->cola_de_mensajes,this->inicio_el_juego, this->map_info);
    this->game_renderer->start();
}

void Juego::joinGame() {
    this->game_renderer = new ClientRenderer(this->cola_de_mensajes,this->inicio_el_juego, this->map_info);
    this->game_renderer->start();
}

void Juego::iniciar_juego() {

    //ventana de juego
    //std::cout<<"El ip es: "<<ip<<std::endl;
    //std::cout<<"El puerto es: "<<puerto<<std::endl;
    this->menu_window();
    //se eligio una configuracion

    

    this->game_renderer->join();
    //this->emisor_de_mensajes->join();
}

Protocol *Juego::getProtocol() {
    return &m_Protocol;
}
