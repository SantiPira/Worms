#pragma once

enum ActionFromClient : uint8_t {
    FC_CREATE_GAME = 0x00,
    FC_JOIN_GAME = 0x01,
    FC_LIST_GAMES = 0x02,
    FC_QUIT = 0x03,
    FC_INVALID = 0x04
};