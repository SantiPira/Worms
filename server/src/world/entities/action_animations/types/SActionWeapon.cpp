#include "world/entities/action_animations/types/SActionWeapon.h"

SActionWeapon::SActionWeapon(uint8_t weaponType, uint8_t actionWeaponType) {
    m_WeaponType = weaponType;
    m_ActionWeaponType = actionWeaponType;
    switch (static_cast<WeaponType>(m_WeaponType)) {
        case WeaponType::AXE:
            if (m_ActionWeaponType == static_cast<uint8_t>(ActionWeaponType::SET_WEAPON)) {
                m_CurrentSprite = SpritesEnum::SPRITE_SETTING_AXE;
            }
            else if (m_ActionWeaponType == static_cast<uint8_t>(ActionWeaponType::HAS_WEAPON)) {
                m_CurrentSprite = SpritesEnum::SPRITE_HAS_AXE;
            } else if (m_ActionWeaponType == static_cast<uint8_t>(ActionWeaponType::UNSET_WEAPON)) {
                m_CurrentSprite = SpritesEnum::SPRITE_SAVING_AXE;
            }
            break;
        case static_cast<WeaponType>(WeaponType::BATE):
            m_CurrentSprite = SpritesEnum::SPRITE_HAS_AXE;
            break;
        default:
            m_CurrentSprite = SpritesEnum::SPRITE_SETTING_AXE;
            break;
    }
}

SpritesEnum SActionWeapon::getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock>& startTime) const {
    auto current = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedSeconds = current - startTime;
    if (m_CurrentSprite == SPRITE_SETTING_AXE) {
        if (elapsedSeconds.count() > 1.0) {
            return SPRITE_HAS_AXE;
        }
    }
    else if (m_CurrentSprite == SPRITE_SAVING_AXE) {
        if (elapsedSeconds.count() > 1.0) {
            return SPRITE_WACCUSE_IDLE;
        }
    }
    return m_CurrentSprite;
}

bool SActionWeapon::hasFinished() {
    return false;
}

void SActionWeapon::reset() {

}

void SActionWeapon::update() {

}