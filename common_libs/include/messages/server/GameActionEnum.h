#pragma once
#include <stdint.h>

enum GameAction : uint8_t {
    TURN_INFO = 0x00,
    WORM_MOVE = 0x01,
    GAME_INFO = 0x09
};
