#include "world/entities/weapons/WeaponFactory.h"

Weapon *WeaponFactory::createWeapon(WeaponID weaponId) {
    switch (weaponId) {
        case WeaponID::AXE:
            return new Axe();
        case WeaponID::BATE:
            return new Bate();
        default:
            return new Axe();
    }
}
