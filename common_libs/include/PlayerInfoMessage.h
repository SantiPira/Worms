#pragma once

#include "ClientMessage.h"
#include "Protocol.h"

class PlayerInfoMessage : public ClientMessage {
private:
    /* data */
    uint8_t action;
    uint16_t gameID;
    uint16_t playerID;
    uint16_t playerPort;
public:
    PlayerInfoMessage();
    void deserialize(Protocol& aProtocol);
    ActionFromClientEnum getAction() const;
};