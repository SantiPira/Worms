#pragma once

#include "GameActionEnum.h"

struct GameUpdate {
    uint8_t player_id;
    GameAction action;
    float x_pos;
    float y_pos;
    GameUpdate() : player_id(0), action(WORM_NONE), x_pos(0), y_pos(0) {}
    GameUpdate(uint8_t player_id, GameAction action, float x_pos, float y_pos) :
        player_id(player_id), action(action), x_pos(x_pos), y_pos(y_pos) {}
};
