#include "world/entities/weapons/WeaponFactory.h"

Weapon *WeaponFactory::createWeapon(WeaponID weaponId, b2Vec2& attackerPosition, b2Vec2& attackedPosition) {
    switch (weaponId) {
        case WeaponID::AXE:
            return new Axe(attackerPosition, attackedPosition);
        default:
            return new Axe(attackerPosition, attackedPosition);
    }
}
