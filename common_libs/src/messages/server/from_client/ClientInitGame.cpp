#include <utility>

#include "../../../../include/messages/server/from_client/ClientInitGame.h"

ClientInitGame::ClientInitGame(ActionFromClient action, int idGame, std::string gameName, std::string mapName,
                               int players) : m_Action(action), m_IdGame(idGame), m_GameName(std::move(gameName)),
                               m_MapName(std::move(mapName)), m_Players(players){}

ClientInitGame::ClientInitGame() : m_Action(ActionFromClient::FC_INVALID), m_IdGame(-1) {}

ActionFromClient ClientInitGame::getAction() const {
    return m_Action;
}

void ClientInitGame::setAction(ActionFromClient action) {
    m_Action = action;
}

bool ClientInitGame::isQuit() const {
    return m_Action == ActionFromClient::FC_CREATE_GAME || m_Action == ActionFromClient::FC_QUIT;
}

int ClientInitGame::getIdGame() const {
    return m_IdGame;
}

void ClientInitGame::setIdGame(int id) {
    m_IdGame = id;
}

std::string ClientInitGame::getGameName() const {
    return m_GameName;
}

void ClientInitGame::setGameName(std::string gameName) {
    m_GameName = std::move(gameName);
}

std::string ClientInitGame::getMapName() const {
    return m_MapName;
}

void ClientInitGame::setMapName(std::string mapName) {
    m_MapName = std::move(mapName);
}

int ClientInitGame::getPlayers() const {
    return m_Players;
}

void ClientInitGame::setPlayers(int players) {
    m_Players = players;
}
