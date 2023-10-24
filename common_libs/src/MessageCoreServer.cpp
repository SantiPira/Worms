#include "../include/MessageCoreGamesAvailables.h"

void MessageCoreGamesAvailables::serialize(Protocol &aProtocol) {
    aProtocol.sendByte(action);
    aProtocol.sendByte(gamesAvailable);
    for (int i = 0; i < gamesAvailable; i++) {
        aProtocol.sendTwoBytes(games[i]);
    }
}

MessageCoreGamesAvailables::MessageCoreGamesAvailables(uint8_t action, uint8_t gamesAvailable, std::vector<uint16_t> games) :
    action(action), gamesAvailable(gamesAvailable), games(std::move(games)) {}

void MessageCoreGamesAvailables::setAction(const uint8_t action) {
    this->action = action;
}

void MessageCoreGamesAvailables::setGamesAvailables(const uint8_t gamesAvailable) {
    this->gamesAvailable = gamesAvailable;
}

void MessageCoreGamesAvailables::setGames(const std::vector<uint16_t> games) {
    this->games = games;
}
