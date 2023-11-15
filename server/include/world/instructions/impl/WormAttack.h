#pragma once

#include "world/instructions/IWormInstruction.h"
#include "messages/user_actions/ActionType.h"

class WormAttack : public IWormInstruction {
public:
    explicit WormAttack(int idPlayer);
    void execute(WWorm* worm) override;
    ~WormAttack() override = default;
};