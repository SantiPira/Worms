#include "client_sender.h"

#include <iostream>

ClientSender::ClientSender(Protocol& protoclo_a_asignar): 
comunicacion_con_server(protoclo_a_asignar) {}

void ClientSender::run() {

    while (/*ES MI TURNO*/ 1) {

        //LEEMOS DE ENTRADA ESTANDAR

        switch (1) {
        case 1:
            //send mensaje al server
            break;
        
        //Mas tipos de acciones

        default:
            break;
        }



    }




}