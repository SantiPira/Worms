#include "world/instructions/impl/WormJump.h"

WormJump::WormJump(int idPlayer) {
    this->setIdPlayer(idPlayer);
}

void WormJump::execute(WWorm *worm) {
    b2Vec2 vel = worm->getVelocity();
    float epsilon = 0.1f;
    if (std::abs(vel.y) < epsilon) {
        float impulse = worm->getBody()->GetMass() * 5;
        vel.y = impulse;
        worm->jump(vel);
    }
}
