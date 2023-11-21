#include "world/instructions/impl/WormJump.h"

WormJump::WormJump(int idPlayer) {
    this->setIdPlayer(idPlayer);
}

void WormJump::execute(WWorm *worm) {
    worm->jump();
}
