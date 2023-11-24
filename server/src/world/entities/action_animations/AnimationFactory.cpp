#include "world/entities/action_animations/AnimationFactory.h"
#include "world/entities/action_animations/types/SActionMove.h"
#include "world/entities/action_animations/types/SActionIdle.h"
#include "world/entities/action_animations/types/SActionJump.h"
#include "world/entities/action_animations/types/SActionWeapon.h"

SpriteAnimations *AnimationFactory::createAnimation(const ActionType& actionType, uint8_t param1, uint8_t param2) {
    switch (actionType) {
        case ActionType::MOVE:
            return new SActionMove();
        case ActionType::JUMP:
            return new SActionJump();
        case ActionType::SET_WEAPON:
            return new SActionWeapon(param1, param2);
        case ActionType::NONE:
            return new SActionIdle();
        case ActionType::STOP_MOVE:
            return new SActionIdle();
        default:
            return new SActionIdle();
    }
}
