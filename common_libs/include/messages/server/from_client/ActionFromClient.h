#pragma once

#include <string>

enum ActionFromClient : uint8_t {
    FC_CREATE_GAME = 0x00,
    FC_JOIN_GAME = 0x01,
    FC_LIST_GAMES = 0x02,
    FC_QUIT = 0x03,
    FC_INVALID = 0x04
};

[[maybe_unused]] inline ActionFromClient getAction(uint8_t action) {
    switch (action) {
        case 0x00:
            return FC_CREATE_GAME;
        case 0x01:
            return FC_JOIN_GAME;
        case 0x02:
            return FC_LIST_GAMES;
        case 0x03:
            return FC_QUIT;
        default:
            return FC_INVALID;
    }
}

[[maybe_unused]] inline ActionFromClient getAction(std::string action) {
    if (action == "create") {
        return FC_CREATE_GAME;
    } else if (action == "join") {
        return FC_JOIN_GAME;
    } else if (action == "list") {
        return FC_LIST_GAMES;
    } else if (action == "quit") {
        return FC_QUIT;
    } else {
        return FC_INVALID;
    }
}