#pragma once
#include <stdint.h>

enum GameAction : uint8_t {
    TURN_INFO = 0x00,
    WORM_MOVE_RIGHT = 0x01,
    WORM_MOVE_LEFT = 0x02,
    WORM_IDLE = 0x03,
    WORM_NONE = 0x04,
    WORM_JUMP = 0x05,
    WORM_FALL = 0x06,
};
