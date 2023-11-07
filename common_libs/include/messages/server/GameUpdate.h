#pragma once

#include "GameActionEnum.h"

struct GameUpdate {
    uint8_t player_id;
    GameAction action;
    float x_pos;
    float y_pos;
};
