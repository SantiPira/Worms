#include "world/instructions/InstructionFactory.h"


IWormInstruction* InstructionFactory::createInstruction(UserAction userAction) {
    switch (userAction.getAction()) {
        case MOVE:
            return new WormMove(userAction.getIdPlayer(),
                                userAction.getParam1() == RIGHT ? Direction::RIGHT : Direction::LEFT);
        case STOP_MOVE:
            return new WormStopMove(userAction.getIdPlayer());
        case JUMP:
            return new WormJump(userAction.getIdPlayer());
        case ATTACK:
            return new WormAttack(userAction.getIdPlayer());
        case SET_WEAPON:
            return new WormSetWeapon(userAction.getIdPlayer(), WeaponID(userAction.getParam1()));
        case UNSET_WEAPON:
            return new WormUnSetWeapon(userAction.getIdPlayer());
        default:
            new WormNone(userAction.getIdPlayer());
    }
    return new WormNone(userAction.getIdPlayer());
}
