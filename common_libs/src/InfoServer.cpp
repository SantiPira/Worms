#include <utility>

#include "../include/InfoServer.h"

InfoServer::InfoServer(uint8_t idMessage, uint8_t games, std::vector<uint16_t> players) : m_IdMessage(idMessage),
m_Games(games), m_Players(std::move(players)){}

uint8_t InfoServer::getGames() const {
    return m_Games;
}

uint8_t InfoServer::getIdMessage() const {
    return m_IdMessage;
}

std::vector<uint16_t> InfoServer::getPlayers() const {
    return m_Players;
}

