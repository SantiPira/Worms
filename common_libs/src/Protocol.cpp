#include "../include/Protocol.h"

Protocol::Protocol(Socket socket): socket(std::move(socket)), wasClosed(false) {}

Protocol::Protocol(const std::string& hostname, const std::string& servname):
        socket(hostname.c_str(), servname.c_str()), wasClosed(false) {}

/*
 * PRIVATE METHODS
 * */
uint8_t Protocol::recvByte() {
    uint8_t aux;
    socket.recvall(&aux, 1, &wasClosed);
    return aux;
}
uint16_t Protocol::recvTwoBytes() {
    uint16_t aux;
    socket.recvall(&aux, 2, &wasClosed);
    return ntohs(aux);
}

std::string Protocol::recvString() {
    uint16_t size = recvTwoBytes();
    std::vector<char> messageFromServer(size + 1);
    socket.recvall(messageFromServer.data(), size, &wasClosed);
    messageFromServer[size] = '\0';
    return messageFromServer.data();
}

void Protocol::sendByte(uint8_t byte) {
    if (!wasClosed)
        socket.sendall(&byte, 1, &wasClosed);
}

void Protocol::sendTwoBytes(uint16_t bytes) {
    if (!wasClosed) {
        uint16_t aux = htons(bytes);
        socket.sendall(&aux, 2, &wasClosed);
    }
}

void Protocol::sendString(const std::string &message) {
    uint16_t size = message.size();
    sendTwoBytes(size);
    socket.sendall(message.c_str(), size, &wasClosed);
}

/*
 * PUBLIC METHODS
 * */

/*------------------------------------SERVER METHODS------------------------------------*/
void Protocol::sendMessage(InfoServer& infoServer) {
    sendByte(infoServer.getIdAction());
    sendByte(infoServer.getGames());
    for (auto& player : infoServer.getPlayers()) {
        sendTwoBytes(player);
    }
}

/*------------------------------------END SERVER METHODS------------------------------------*/

/*------------------------------------CLIENT METHODS------------------------------------*/


/*------------------------------------END CLIENT METHODS------------------------------------*/

void Protocol::close() { socket.close(); }
void Protocol::shutdown(int mode) { socket.shutdown(mode); }
Protocol::~Protocol() {
    try {
        socket.shutdown(SHUT_RDWR);
        socket.close();
    } catch (const LibError& e) {
        socket.close();
    }
}
bool Protocol::isClosed() const { return wasClosed; }

void Protocol::recvClientInitGame(ClientInitGame &clientInitGame) {
    clientInitGame.setAction(getAction(recvByte()));
    clientInitGame.setIdGame(recvByte());
    clientInitGame.setGameName(recvString());
    clientInitGame.setMapName(recvString());
    clientInitGame.setPlayers(recvByte());
}

void Protocol::recvServerInfo(InfoServer& infoServer) {
    uint8_t action = recvByte();
    infoServer.setIdAction(ActionToClient(action));
    uint8_t games = recvByte();
    infoServer.setGames(games);
    std::vector<uint16_t> playersList;
    for (int i = 0; i < games; i++) {
        uint16_t players = recvTwoBytes();
        playersList.push_back(players);
    }
    infoServer.setPlayers(playersList);
}




