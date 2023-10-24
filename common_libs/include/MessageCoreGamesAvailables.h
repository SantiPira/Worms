#pragma once

#include <vector>
#include "ToClientMessage.h"
#include "Protocol.h"

class MessageCoreGamesAvailables : public ToClientMessage {
private:
    /* data */
    uint8_t action;
    uint8_t gamesAvailable;
    std::vector<uint16_t> games;
public:
    MessageCoreGamesAvailables(uint8_t action, uint8_t gamesAvailable, std::vector<uint16_t> games);
    void serialize(Protocol& aProtocol) override;

    void setAction(const uint8_t action);
    void setGamesAvailables(const uint8_t gamesAvailable);
    void setGames(const std::vector<uint16_t> games);
};