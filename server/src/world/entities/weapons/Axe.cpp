#include "world/entities/weapons/impl/Axe.h"

Axe::Axe(b2Vec2& attackerPosition, b2Vec2& attackedPosition) : damage(50), distance(1.5f) {
    this->m_WeaponId = WeaponID::AXE;
    this->m_AttackerPosition = attackerPosition;
    this->m_AttackedPosition = attackedPosition;
}

void Axe::attack(WWorm *wormAttacked) {
    float distanceBetween = b2Distance(this->m_AttackerPosition, this->m_AttackedPosition);
    if (distanceBetween <= distance) {
        wormAttacked->receiveDamage(damage);
    }
}

void Axe::setWeaponId(WeaponID weaponId) {
    this->m_WeaponId = weaponId;
}

WeaponID Axe::getWeaponId() const {
    return this->m_WeaponId;
}
