#include "world/entities/action_animations/types/SActionWeapon.h"

SActionWeapon::SActionWeapon(uint8_t weaponType, uint8_t actionWeaponType) {
    m_WeaponType = weaponType;
    m_ActionWeaponType = actionWeaponType;
    switch (m_WeaponType) {
        case WeaponType::AXE:
            if (m_ActionWeaponType == ActionWeaponType::SET_WEAPON)
                m_CurrentSprite = SpritesEnum::SPRITE_SETTING_AXE;
            else if (m_ActionWeaponType == ActionWeaponType::HAS_WEAPON)
                m_CurrentSprite = SpritesEnum::SPRITE_HAS_AXE;
            else if (m_ActionWeaponType == ActionWeaponType::UNSET_WEAPON)
                m_CurrentSprite = SpritesEnum::SPRITE_SAVING_AXE;
            break;
        case WeaponType::BATE:
            m_CurrentSprite = SpritesEnum::SPRITE_HAS_AXE;
            break;
        default:
            m_CurrentSprite = SpritesEnum::SPRITE_SETTING_AXE;
            break;
    }
}