#pragma once

#include "world/entities/action_animations/SpriteAnimations.h"
#include "messages/user_actions/WeaponID.h"

class SActionAttack : public SpriteAnimations {
private:
    WeaponID m_WeaponId;
public:
    explicit SActionAttack(uint8_t weaponId);
    void update() override;
    void reset() override;
    bool hasFinished() override;
    [[nodiscard]] SpritesEnum getCurrentSprite(const std::chrono::time_point<std::chrono::system_clock>& startTime) const override;
};