#pragma once

#include <cstdint>

enum ActionType : uint8_t {
    MOVE = 0X00,
    STOP_MOVE = 0X01,
    JUMP = 0X02,
    NONE = 0X03
};


enum Direction : uint8_t {
    LEFT = 0X00,
    RIGHT = 0X01
};

inline Direction operator!(Direction dir) {
    return dir == LEFT ? RIGHT : LEFT;
}