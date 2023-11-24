#pragma once

#include <cstdint>

enum ActionType : uint8_t {
    MOVE = 0X00,
    STOP_MOVE = 0X01,
    JUMP = 0X02,
    NONE = 0X03,
    ATTACK = 0X04,
    STOP_ATTACK = 0X05,
    SET_WEAPON = 0X06,
    UNSET_WEAPON = 0X07,
    DECREASE_ANGLE = 0X08,
    INCREASE_ANGLE = 0X09
};


enum Direction : uint8_t {
    LEFT = 0X00,
    RIGHT = 0X01
};

inline Direction operator!(Direction dir) {
    return dir == LEFT ? RIGHT : LEFT;
}
