#include "client_reciever.h"

#include <iostream>

 ClientReciever::ClientReciever(ClientProtocol &protocolo_a_asginar):
 comunicacion_con_server(protocolo_a_asginar) {}

 void ClientReciever::run(){
    
    std::cout << "Soy el reciever y acabo de lanzarme\n";

 }