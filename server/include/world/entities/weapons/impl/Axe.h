#pragma once

#include "world/entities/weapons/Weapon.h"
#include "../../../../../../Box2D/include/box2d/box2d.h"
#include "world/entities/WWorm.h"

class WWorm;
class Axe : public Weapon {
private:
    int damage;
    float distance;
public:
    Axe(b2Vec2& attackerPosition, b2Vec2& attackedPosition);
    void attack(WWorm* worm) override;

    ~Axe() override = default;
};