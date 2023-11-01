#include <iostream>
#include "../include/CreateGameHandler.h"


void CreateGameHandler::handle(ClientInitGame &initGame) {
    std::cout<<"El mapa es: "<<initGame.getMapName()<<std::endl;
    std::cout<<"El nombre es: "<<initGame.getGameName()<<std::endl;
    std::cout<<"La cantidad de jugadores es: "<<initGame.getPlayers()<<std::endl;
}
