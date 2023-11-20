#pragma once

#include "world/entities/weapons/Weapon.h"
#include "world/entities/WWorm.h"

class Axe : public Weapon {
private:
    int damage;
    float distance;
public:
    Axe(b2Vec2& attackerPosition, b2Vec2& attackedPosition);
    void attack(WWorm* worm) override;

    void setWeaponId(WeaponID weaponId) override;
    WeaponID getWeaponId() const override;

    ~Axe() override = default;
};