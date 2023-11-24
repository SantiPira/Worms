#include "world/entities/action_animations/types/SActionMove.h"

SActionMove::SActionMove() {
    m_CurrentSprite = SpritesEnum::SPRITE_WALK;
}

SpritesEnum SActionMove::getCurrentSprite() const {
    return m_CurrentSprite;
}

bool SActionMove::hasFinished() {
    return false;
}

void SActionMove::reset() {

}

void SActionMove::update() {

}
