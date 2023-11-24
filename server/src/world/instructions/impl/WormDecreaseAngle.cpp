#include "world/instructions/impl/WormDecreaseAngle.h"

WormDecreaseAngle::WormDecreaseAngle(int idPlayer) {
    this->setIdPlayer(idPlayer);
}

void WormDecreaseAngle::execute(WWorm *worm) {
    float radianAngle = worm->getWeaponAngle();
    float gradAngle = radianAngle * 180 / b2_pi;
    if (gradAngle - 5.0f < 0) {
        gradAngle = 0;
    } else {
        gradAngle -= 5.0f;
    }
    radianAngle = gradAngle * b2_pi / 180;
    worm->setWeaponAngle(radianAngle);
}

