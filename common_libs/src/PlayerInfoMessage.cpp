#include "../include/PlayerInfoMessage.h"

PlayerInfoMessage::PlayerInfoMessage() {}

void PlayerInfoMessage::deserialize(Protocol &aProtocol) {
    action = getActionFromClientEnum(aProtocol.recvByte());
    if (action == ActionFromClientEnum::CL_JOIN_GAME) {
        gameID = aProtocol.recvByte();
    }
}

ActionFromClientEnum PlayerInfoMessage::getAction() const {
    return getActionFromClientEnum(action);
}
