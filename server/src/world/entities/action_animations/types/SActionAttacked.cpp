#include "world/entities/action_animations/types/SActionAttacked.h"

SActionAttacked::SActionAttacked() {
    this->m_CurrentSprite = SpritesEnum::SPRITE_WACCUSE_GETTING_DAMAGE;
}

SpritesEnum SActionAttacked::getCurrentSprite(
        const std::chrono::time_point<std::chrono::system_clock> &startTime) const {
    auto current = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedSeconds = current - startTime;

    if (elapsedSeconds.count() > 3.0) {
        return SPRITE_WACCUSE_IDLE;
    }

    return m_CurrentSprite;
}
