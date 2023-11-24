#include "world/entities/action_animations/types/SActionIdle.h"

SActionIdle::SActionIdle() {
    this->m_CurrentSprite = SpritesEnum::SPRITE_WACCUSE_IDLE;
}

SpritesEnum SActionIdle::getCurrentSprite() const {
    return this->m_CurrentSprite;
}

bool SActionIdle::hasFinished() {
    return false;
}

void SActionIdle::reset() {

}

void SActionIdle::update() {

}
