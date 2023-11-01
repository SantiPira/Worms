#pragma once

#include "../../common_libs/include/messages/server/from_client/ClientInitGame.h"

class HandlerInitGame {
public:
    virtual void handle(ClientInitGame& initGame) = 0;
};
