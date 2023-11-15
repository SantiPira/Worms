#pragma once

#include "world/instructions/IWormInstruction.h"
#include "messages/user_actions/Weapon.h"

class WormSetWeapon : public IWormInstruction {
private:
    Weapon m_Weapon;
public:
    explicit WormSetWeapon(int idPlayer, Weapon weapon);
    void execute(WWorm* worm) override;
    ~WormSetWeapon() override = default;
};