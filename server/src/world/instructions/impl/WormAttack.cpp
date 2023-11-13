#include "world/instructions/impl/WormAttack.h"

WormAttack::WormAttack(int idPlayer) {
    this->setIdPlayer(idPlayer);
}

void WormAttack::execute(WWorm *worm) {
    worm->attack();
}
