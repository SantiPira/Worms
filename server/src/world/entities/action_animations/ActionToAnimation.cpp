#include "world/entities/action_animations/ActionToAnimation.h"

ActionToAnimation::ActionToAnimation() : m_Action(ActionType::NONE), m_StartTime(std::chrono::system_clock::now()) {}

SpritesEnum ActionToAnimation::getCurrentSprite() const {
    SpriteAnimations* animation = AnimationFactory::createAnimation(m_Action);
    SpritesEnum sprite = animation->getCurrentSprite();
    delete animation;
    return sprite;
}

void ActionToAnimation::resetAnimation() {
    this->m_Action = ActionType::NONE;
    this->m_StartTime = std::chrono::system_clock::now();
}

void ActionToAnimation::setAction(ActionType action) {
    this->m_Action = action;
}


