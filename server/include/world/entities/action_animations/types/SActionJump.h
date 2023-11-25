#pragma once

#include <chrono>
#include "world/entities/action_animations/SpriteAnimations.h"

class SActionJump : public SpriteAnimations {
public:
    SActionJump();
    void update() override;
    void reset() override;
    bool hasFinished() override;
    [[nodiscard]] SpritesEnum getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock>& startTime) const override;
};