#include "world/entities/weapons/impl/Bate.h"

Bate::Bate(b2Vec2 &attackerPosition, b2Vec2 &attackedPosition) {
    this->m_WeaponId = WeaponID::BATE;
    this->m_AttackerPosition = attackerPosition;
    this->m_AttackedPosition = attackedPosition;
}

void Bate::attack(WWorm *worm) {
    float distanceBetween = b2Distance(this->m_AttackerPosition, this->m_AttackedPosition);
    if (distanceBetween <= distance) {
        worm->receiveDamage(damage);
    }
}
