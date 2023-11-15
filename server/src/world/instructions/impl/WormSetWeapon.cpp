#include "world/instructions/impl/WormSetWeapon.h"

WormSetWeapon::WormSetWeapon(int idPlayer, Weapon weapon) {
    this->setIdPlayer(idPlayer);
    m_Weapon = weapon;
}

void WormSetWeapon::execute(WWorm *worm) {
    worm->setWeapon(m_Weapon);
}
