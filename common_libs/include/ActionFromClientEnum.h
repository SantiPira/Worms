#pragma once

enum ActionFromClientEnum : uint8_t {
    CL_QUIT = 0X00,
    CL_CREATE_GAME = 0X01,
    CL_JOIN_GAME = 0X02,
    CL_LIST_GAMES = 0X03,
    CL_INVALID_ACTION_FROM_CLIENT = 0XFF
};

[[maybe_unused]] inline ActionFromClientEnum getActionFromClientEnum(uint8_t action) {
    if (action == ActionFromClientEnum::CL_QUIT) {
        return CL_QUIT;
    } else if (action == ActionFromClientEnum::CL_CREATE_GAME) {
        return CL_CREATE_GAME;
    } else if (action == ActionFromClientEnum::CL_JOIN_GAME) {
        return CL_JOIN_GAME;
    } else if (action == ActionFromClientEnum::CL_LIST_GAMES) {
        return CL_LIST_GAMES;
    }
    return CL_INVALID_ACTION_FROM_CLIENT;
}