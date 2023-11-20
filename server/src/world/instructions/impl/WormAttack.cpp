#include "world/instructions/impl/WormAttack.h"

WormAttack::WormAttack(int idPlayer, uint8_t param1) {
    this->setIdPlayer(idPlayer);
    this->m_Param1 = param1;
}

void WormAttack::execute(WWorm *worm) {
    worm->attack();
}
