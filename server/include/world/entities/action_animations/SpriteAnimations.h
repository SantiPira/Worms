#pragma once

#include "messages/sprites/SpritesEnum.h"
#include <chrono>

class SpriteAnimations {
protected:
    SpritesEnum m_CurrentSprite = SPRITE_WACCUSE_IDLE;
public:
    virtual ~SpriteAnimations() = default;
    virtual void update() = 0;
    virtual void reset() = 0;
    virtual bool hasFinished() = 0;
    [[nodiscard]] virtual SpritesEnum
    getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock>& startTime) const = 0;
};