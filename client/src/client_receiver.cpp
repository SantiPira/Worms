#include "client_receiver.h"

ClientReceiver::ClientReceiver(Protocol& protocolo_a_asignar, ProtectedQueue<std::string>& cola_a_asignar):
comunicacion_con_server(protocolo_a_asignar), cola_de_mensajes(cola_a_asignar) {}


void  ClientReceiver::run() {

    std::cout << "SOY EL RECEIVER Y ACABO DE LANZARME\n";

    while (/*EL JUEGO SIGA EN CURSO */ 1) {
        //game_info = this->comunicacion_con_server.recvGameInfo(); -> MIRAR BIEN QUE SE RECIBE.
        //this->cola_de_mensajes.try_push(game_info);
    }


}
