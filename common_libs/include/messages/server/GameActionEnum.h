#pragma once
#include <stdint.h>

enum GameAction : uint8_t {
    TURN_INFO = 0x00,
    WORM_MOVE_RIGHT = 0x01,
    WORM_MOVE_LEFT = 0x02,
    WORM_IDLE = 0x03
};
