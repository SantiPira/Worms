#include "client_sender.h"

#include <iostream>

ClientSender::ClientSender(const char* ip, const char* puerto):
comunicacion_con_server(ip, puerto) {}

void ClientSender::run(){

    std::cout << "Soy el sender y acabo de lanzarme\n";

    ClientReciever thread_recpetor(comunicacion_con_server);


    thread_recpetor.start();
    thread_recpetor.join();
}
