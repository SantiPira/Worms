#pragma once
#include <stdint.h>

enum GameAction : uint8_t {
    TURN_INFO = 0x00,
    WORM_MOVE = 0x01,
    WORM_IDLE = 0x02
};
