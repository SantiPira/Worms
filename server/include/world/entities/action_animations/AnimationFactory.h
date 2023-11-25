#pragma once

#include "SpriteAnimations.h"
#include "messages/user_actions/ActionType.h"

class AnimationFactory {
public:
    AnimationFactory() = default;
    static SpriteAnimations* createAnimation(const ActionType& actionType, uint8_t param1 = 0, uint8_t param2 = 0);
    static SpriteAnimations* createDeathAnimation();

    ~AnimationFactory() = default;

    AnimationFactory(const AnimationFactory&) = default;
    AnimationFactory& operator=(const AnimationFactory&) = default;
    AnimationFactory(AnimationFactory&&) noexcept = default;
    AnimationFactory& operator=(AnimationFactory&&) noexcept = default;
};