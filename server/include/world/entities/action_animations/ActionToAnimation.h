#pragma once

#include <chrono>
#include "messages/user_actions/ActionType.h"
#include "messages/sprites/SpritesEnum.h"
#include "world/entities/action_animations/SpriteAnimations.h"
#include "world/entities/action_animations/AnimationFactory.h"

class WWorm;

class ActionToAnimation {
private:
    ActionType m_Action;
    std::chrono::time_point<std::chrono::system_clock> m_StartTime;
    uint8_t m_Param1 = 0;
    uint8_t m_Param2 = 0;
public:
    ActionToAnimation();

    void resetAnimation();

    [[nodiscard]] SpritesEnum getCurrentSprite(WWorm* worm) const;

    void setAction(ActionType action, uint8_t param1 = 0, uint8_t param2 = 0);
};