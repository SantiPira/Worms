#include "client_sender.h"

#include <iostream>

ClientSender::ClientSender(GameInfo info_de_juego, Protocol& protoclo_a_asignar): 
comunicacion_con_server(protoclo_a_asignar),
info_inicial(info_de_juego){}

void ClientSender::run() {

    if (this->info_inicial.getIdAction() == InitGameEnum::CREATE_GAME) {
        this->comunicacion_con_server.sendGameInfo(this->info_inicial);
    } else if (this->info_inicial.getIdAction() == (InitGameEnum::LIST_GAMES)) {
        this->comunicacion_con_server.sendGameInfo(this->info_inicial);
    } // LANZAR EXCEPCION!

    //looop


}