#include "world/entities/weapons/impl/Bate.h"

Bate::Bate() {
    this->m_WeaponId = WeaponID::BATE;
}

void Bate::attack(WWorm *attacker, WWorm* attacked) {
//    float distanceBetween = b2Distance(this->m_AttackerPosition, this->m_AttackedPosition);
//    if (distanceBetween <= distance) {
//        worm->receiveDamage(damage);
//    }
}

void Bate::setWeaponId(WeaponID weaponId) {
    this->m_WeaponId = weaponId;
}

WeaponID Bate::getWeaponId() const {
    return this->m_WeaponId;
}
