#pragma once

#include <cstdint>

enum ActionType : uint8_t {
    MOVE = 0X00,
    STOP_MOVE = 0X01,
    NONE = 0X02
};


enum Direction : uint8_t {
    LEFT = 0X00,
    RIGHT = 0X01
};

inline Direction operator!(Direction dir) {
    return dir == LEFT ? RIGHT : LEFT;
}