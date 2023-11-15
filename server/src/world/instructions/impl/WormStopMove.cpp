#include "world/instructions/impl/WormStopMove.h"

WormStopMove::WormStopMove(int idPlayer) {
    setIdPlayer(idPlayer);

}

void WormStopMove::execute(WWorm *worm) {
    worm->stopMove();
}
