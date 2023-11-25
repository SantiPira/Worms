#pragma once

#include <cstdint>
#include <chrono>
#include "world/entities/action_animations/SpriteAnimations.h"

enum class WeaponType : uint8_t {
    AXE = 0x00,
    BATE = 0x01
};

enum class ActionWeaponType : uint8_t {
    SET_WEAPON = 0x00,
    HAS_WEAPON = 0x01,
    UNSET_WEAPON = 0x02
};
class SActionWeapon : public SpriteAnimations {
private:
    uint8_t m_WeaponType;
    uint8_t  m_ActionWeaponType;
public:
    SActionWeapon(uint8_t weaponType, uint8_t actionType);
    void update() override;
    void reset() override;
    bool hasFinished() override;
    [[nodiscard]] SpritesEnum getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock>& startTime) const override;
};