#pragma once

#include "HandlerInitGame.h"

class CreateGameHandler : public HandlerInitGame {
public:
    CreateGameHandler() = default;
    void handle(ClientInitGame& initGame) override;
};