#include "world/entities/action_animations/types/SActionJump.h"

SActionJump::SActionJump() {
    m_CurrentSprite = SpritesEnum::SPRITE_JUMPING;
}

void SActionJump::update() {

}

void SActionJump::reset() {

}

bool SActionJump::hasFinished() {
    return false;
}

SpritesEnum SActionJump::getCurrentSprite() const {
    return m_CurrentSprite;
}
