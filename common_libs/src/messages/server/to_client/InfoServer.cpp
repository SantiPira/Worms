#include <utility>

#include "../../../../include/messages/server/to_client/InfoServer.h"

InfoServer::InfoServer(ActionToClient idAction, uint8_t games, std::vector<uint16_t> players) : m_IdAction(idAction),
m_Games(games), m_Players(std::move(players)){}

InfoServer::InfoServer() : m_IdAction(ActionToClient::TC_INVALID), m_Games(0), m_Players() {}

uint8_t InfoServer::getGames() const {
    return m_Games;
}

ActionToClient InfoServer::getIdAction() const {
    return m_IdAction;
}

std::vector<uint16_t> InfoServer::getPlayers() const {
    return m_Players;
}

void InfoServer::setIdAction(ActionToClient idAction) {
    m_IdAction = idAction;
}

void InfoServer::setGames(uint8_t games) {
    m_Games = games;
}

void InfoServer::setPlayers(std::vector<uint16_t> players) {
    m_Players = std::move(players);
}


