#include "client_protocol.h"

ClientProtocol::ClientProtocol(const char* ip, const char* puerto): 
socket_cliente(ip, puerto) {}
