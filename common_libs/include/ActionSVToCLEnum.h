#pragma once

#include <cstdint>

enum ActionSVToCLEnum : uint8_t {
    SV_CORE_MESSAGE = 0X00,
    SV_GAME_MESSAGE = 0X01
};

[[maybe_unused]] inline ActionSVToCLEnum getActionSVToCLEnum(uint8_t action) {
    if (action == ActionSVToCLEnum::SV_CORE_MESSAGE) {
        return SV_CORE_MESSAGE;
    } else if (action == ActionSVToCLEnum::SV_GAME_MESSAGE) {
        return SV_GAME_MESSAGE;
    }
    return SV_CORE_MESSAGE;
}