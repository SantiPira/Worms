#pragma once

#include "world/entities/action_animations/SpriteAnimations.h"
#include <chrono>

class SActionIdle : public SpriteAnimations {
 public:
    SActionIdle();
    void update() override;
    void reset() override;
    bool hasFinished() override;
    [[nodiscard]] SpritesEnum getCurrentSprite() const override;
};