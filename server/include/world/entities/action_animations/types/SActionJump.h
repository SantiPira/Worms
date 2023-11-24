#pragma once

#include "world/entities/action_animations/SpriteAnimations.h"

class SActionJump : public SpriteAnimations {
public:
    SActionJump();
    void update() override;
    void reset() override;
    bool hasFinished() override;
    [[nodiscard]] SpritesEnum getCurrentSprite() const override;
};