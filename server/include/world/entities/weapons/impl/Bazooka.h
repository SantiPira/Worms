#pragma once

#include "world/entities/weapons/Weapon.h"
#include "world/entities/WWorm.h"

class Bazooka : public Weapon {
private:
    int damage;
    float distance;
    float radius{3.0f};
public:
    Bazooka();
    void attack(WWorm* attacker, WWorm* attacked, uint8_t force) override;

    void setWeaponId(WeaponID weaponId) override;
    WeaponID getWeaponId() const override;

    ~Bazooka() override = default;
};
