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

void Protocol::sendGameInfo(GameInfo& gameInfo) {
    sendByte(gameInfo.getIdAction());
    sendByte(gameInfo.getGameProperties().size());
    for (auto& gameProperty : gameInfo.getGameProperties()) {
        sendByte(gameProperty.m_idGame);
        sendString(gameProperty.m_GameName);
        sendString(gameProperty.m_MapName);
        sendByte(gameProperty.m_Players);
    }
}

void Protocol::sendMap(std::reference_wrapper<std::vector<Grd>> map) {
    sendByte(map.get().size());
    for (auto& grd : map.get()) {
        sendByte(grd.grdType);
        sendTwoBytes(grd.x);
        sendTwoBytes(grd.y);
    }
}

void Protocol::sendGameUpdate(GameUpdate &update) {
    sendByte(update.player_id);
    sendByte(update.action);
    sendTwoBytes(update.x_pos);
    sendTwoBytes(update.y_pos);
}

GameInfo Protocol::recvGameInfo() {
    GameInfo gameInfo;
    gameInfo.setIdAction(InitGameEnum(recvByte()));
    uint8_t size = recvByte();
    std::vector<GameProperty> gameProperties;
    for (int i = 0; i < size; i++) {
        int idGame = recvByte();
        std::string gameName = recvString();
        std::string mapName = recvString();
        int players = recvByte();
        gameProperties.emplace_back(idGame, gameName, mapName, players);
    }
    gameInfo.setGameProperties(gameProperties);
    return gameInfo;
}

std::vector<Grd> Protocol::recvMap() {
    std::vector<Grd> map;
    uint8_t size = recvByte();
    for (int i = 0; i < size; i++) {
        uint8_t grdType = recvByte();
        uint16_t x = recvTwoBytes();
        uint16_t y = recvTwoBytes();
        map.emplace_back(grdType, x, y);
    }
    return map;
}

GameUpdate Protocol::recvGameUpdate() {
    GameUpdate update{};
    update.player_id = recvByte();
    update.action = GameAction(recvByte());
    update.x_pos = recvTwoBytes();
    update.y_pos = recvTwoBytes();
    return update;
}

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

void Protocol::sendUserAction(UserAction action) {
    sendByte(action.getAction());
    sendByte(action.getIdPlayer());
    if (action.getAction() == ActionType::MOVE) {
        sendByte(action.getParam1());
    }
}

