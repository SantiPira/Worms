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
    MapInfo mapInfo;
    getMapInfo(cantidad_jugadores, mapInfo);
    this->game_renderer = new ClientRenderer(this->cola_de_mensajes,this->inicio_el_juego, this->map_info, m_Protocol);
    this->game_renderer->start();

    //Temporal
    this->game_renderer->join();

}

void Juego::getMapInfo(const string &cantidad_jugadores, MapInfo &mapInfo) {
    
    vector<Grd> map = m_Protocol.recvMap();

    mapInfo.cantBeams = map.size();
    mapInfo.grd = map;
    mapInfo.cantWorms = stoi(cantidad_jugadores);

    for (int i = 0; i < mapInfo.cantWorms; i++) {
        mapInfo.worms.push_back(m_Protocol.recvGameUpdate());
    }
}

void Juego::joinGame() {


    //Hacer con la cantidad de jugadores.

    MapInfo mapInfo;
    getMapInfo("2", mapInfo); // Aca deberia existir la cantidad de jugadores para el mapa.

    this->game_renderer = new ClientRenderer(this->cola_de_mensajes,this->inicio_el_juego, this->map_info, m_Protocol);
    this->game_renderer->start();

    //Temporal
    this->game_renderer->join();
    
}

Protocol *Juego::getProtocol() {
    return &m_Protocol;
}
