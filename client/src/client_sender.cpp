#include "client_sender.h"

#include <iostream>

ClientSender::ClientSender(ClientProtocol &protocolo_a_asignar, std::string nombre_mapa, 
    std::string nombre_partida, std::string cantidad_jugadores):
comunicacion_con_server(protocolo_a_asignar) {
    this->nombre_mapa = nombre_mapa;
    this->nombre_partida = nombre_partida;
    this->cantidad_jugadores = cantidad_jugadores;
    this->se_creo_partida_nueva = true;
}

ClientSender::ClientSender(ClientProtocol &protocolo_a_asignar):
comunicacion_con_server(protocolo_a_asignar) {}



void ClientSender::run(){
    
    std::cout << "Javier, llegaste mas lejos\n";

    std::cout << this->nombre_mapa << "\n";
    std::cout << this->nombre_partida << "\n";
    std::cout << this->cantidad_jugadores << "\n";


    ClientReciever thread_recpetor(comunicacion_con_server);
    thread_recpetor.start();
    thread_recpetor.join();
}
