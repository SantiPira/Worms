#include "world/instructions/impl/WormUnSetWeapon.h"

WormUnSetWeapon::WormUnSetWeapon(int idPlayer) {
    this->setIdPlayer(idPlayer);
}

void WormUnSetWeapon::execute(WWorm *worm) {
    worm->setWeapon(WeaponID::NO_WEAPON);
}


