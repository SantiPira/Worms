#include "world/instructions/impl/WormIncreaseAngle.h"

WormIncreaseAngle::WormIncreaseAngle(int idPlayer) {
    this->setIdPlayer(idPlayer);
}

void WormIncreaseAngle::execute(WWorm *worm) {
    float radianAngle = worm->getWeaponAngle();
    float gradAngle = radianAngle * 180.0f / b2_pi;
    gradAngle = gradAngle + 5.0f;
    if (gradAngle > 90.0f) {
        gradAngle = 90.0f;
    }
    float angle = gradAngle * b2_pi / 180.0f;
    worm->setWeaponAngle(angle);
}
