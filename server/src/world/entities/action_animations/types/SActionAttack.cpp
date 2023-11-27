#include "world/entities/action_animations/types/SActionAttack.h"

SActionAttack::SActionAttack(uint8_t weaponId) {
    m_WeaponId = WeaponID(weaponId);
}

SpritesEnum SActionAttack::getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock> &startTime) const {
    auto current = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedSeconds = current - startTime;
    switch (m_WeaponId) {
        case WeaponID::AXE:
            if (elapsedSeconds.count() > 1.0) {
                return SPRITE_WACCUSE_IDLE;
            }
            return SPRITE_ATTACK_AXE;
        case NO_WEAPON:
            return SPRITE_WACCUSE_IDLE;
        case BATE:
            if (elapsedSeconds.count() > 1.0) {
                return SPRITE_WACCUSE_IDLE;
            }
            return SPRITE_ATTACK_BATE;
        case BAZOOKA:
            if (elapsedSeconds.count() > 1.0) {
                return SPRITE_WACCUSE_IDLE;
            }
            return SPRITE_ATTACK_BAZOOKA;
        default:
            break;
    }
    return m_CurrentSprite;
}
