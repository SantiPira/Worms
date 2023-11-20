#include "world/instructions/impl/WormMove.h"

WormMove::WormMove(int idPlayer, Direction m_Dir) : m_Dir(m_Dir) {
    setIdPlayer(idPlayer);
}

void WormMove::execute(WWorm* worm) {
    worm->move(m_Dir);
}


