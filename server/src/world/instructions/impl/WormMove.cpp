#include "world/instructions/impl/WormMove.h"

WormMove::WormMove(int idPlayer, Direction m_Dir) : m_Dir(m_Dir) {
    setIdPlayer(idPlayer);
}

void WormMove::execute(WWorm* worm) {
    float velocity;
    m_Dir == Direction::LEFT ? velocity = -5 : velocity = 5;
    worm->setVelocity(b2Vec2(velocity, 0));
    worm->setDirection(m_Dir);
}


