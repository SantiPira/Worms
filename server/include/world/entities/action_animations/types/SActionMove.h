#pragma once

#include <chrono>
#include "world/entities/action_animations/SpriteAnimations.h"

class SActionMove : public SpriteAnimations {
public:
    SActionMove();
    void update() override;
    void reset() override;
    bool hasFinished() override;
    [[nodiscard]] SpritesEnum getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock>& startTime) const override;
};