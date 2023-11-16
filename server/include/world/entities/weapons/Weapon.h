#pragma once

#include "../../../../../Box2D/include/box2d/box2d.h"
#include "messages/user_actions/WeaponID.h"
#include "world/entities/WWorm.h"

class WWorm;
class Weapon {
protected:
    WeaponID m_WeaponId = WeaponID::NO_WEAPON;
    b2Vec2 m_AttackerPosition{};
    b2Vec2 m_AttackedPosition{};
public:
    virtual void attack(WWorm* worm) = 0;
    void setWeaponId(WeaponID weaponId) {
        this->m_WeaponId = weaponId;
    }

    [[nodiscard]] WeaponID getWeaponId() const {
        return m_WeaponId;
    }

    //destructor
    virtual ~Weapon() = default;
};