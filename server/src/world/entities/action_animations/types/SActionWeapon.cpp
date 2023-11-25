#include "world/entities/action_animations/types/SActionWeapon.h"

SActionWeapon::SActionWeapon(uint8_t weaponType, uint8_t actionWeaponType) {
    m_WeaponType = WeaponID(weaponType);
    m_ActionWeaponType = ActionWeaponType(actionWeaponType);
    switch (m_WeaponType) {
        case WeaponID::AXE:
            m_Sequence = buildAxeSequence();
            break;
        case WeaponID::BATE:
            m_Sequence = buildBateSequence();
            break;
        default:
            m_Sequence = buildAxeSequence();
            break;
    }
}

SpritesEnum SActionWeapon::getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock>& startTime) const {
    auto current = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedSeconds = current - startTime;
    switch (m_ActionWeaponType) {
        case ActionWeaponType::ACTION_WEAPON_TYPE_SET_WEAPON:
            if (elapsedSeconds.count() > 1.0) {
                return m_Sequence.hasWeapon;
            }
            return m_Sequence.setWeapon;
        case ActionWeaponType::ACTION_WEAPON_TYPE_HAS_WEAPON:
            if (elapsedSeconds.count() > 1.0) {
                return m_Sequence.saveWeapon;
            }
            return m_Sequence.hasWeapon;
        case ActionWeaponType::ACTION_WEAPON_TYPE_UNSET_WEAPON:
            if (elapsedSeconds.count() > 1.0) {
                return SPRITE_WACCUSE_IDLE;
            }
            return m_Sequence.saveWeapon;
        default:
            break;
    }
    return m_CurrentSprite;
}

Squence SActionWeapon::buildAxeSequence() {
    Squence sequence{};
    sequence.setWeapon = SpritesEnum::SPRITE_SETTING_AXE;
    sequence.hasWeapon = SpritesEnum::SPRITE_HAS_AXE;
    sequence.saveWeapon = SpritesEnum::SPRITE_SAVING_AXE;
    return sequence;
}

Squence SActionWeapon::buildBateSequence() {
    Squence sequence{};
    sequence.setWeapon = SpritesEnum::SPRITE_SETTING_BATE;
    sequence.hasWeapon = SpritesEnum::SPRITE_HAS_BATE;
    sequence.saveWeapon = SpritesEnum::SPRITE_SAVING_BATE;
    return sequence;
}
