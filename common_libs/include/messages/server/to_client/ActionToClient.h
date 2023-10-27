#pragma once

enum ActionToClient : uint8_t {
    TC_INFO = 0x00,
    TC_GAME_CREATED = 0x01,
    TC_GAME_JOINED = 0x02,
    TC_GAME_LIST = 0x03,
    TC_GAME_START = 0x04,
    TC_GAME_END = 0x05,
    TC_GAME_STATE = 0x06,
    TC_GAME_QUIT = 0x07,
    TC_INVALID = 0x08
};