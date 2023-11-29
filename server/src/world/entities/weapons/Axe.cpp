#include "world/entities/weapons/impl/Axe.h"

Axe::Axe() : damage(1), distance(1.5f) {
    this->m_WeaponId = WeaponID::AXE;
}

void Axe::attack(WWorm *attacker, WWorm *attacked, uint8_t force) {
    if (attacked->getId() == attacker->getId()) {
        return;
    }
    float distanceBetween = b2Distance(attacker->getPosition(), attacked->getPosition());
    if (distanceBetween <= distance) {
        attacker->getActionToAnimation()->resetAnimation();
        attacker->getActionToAnimation()->setAction(ActionType::ATTACK, m_WeaponId);
        attacker->setIsAttacking(true);
        attacked->receiveDamage(damage);
    }
}

void Axe::setWeaponId(WeaponID weaponId) {
    this->m_WeaponId = weaponId;
}

WeaponID Axe::getWeaponId() const {
    return this->m_WeaponId;
}
