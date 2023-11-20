#pragma once

#include "world/entities/weapons/Weapon.h"
#include "../../../../../../Box2D/include/box2d/box2d.h"
#include "world/entities/WWorm.h"

class WWorm;

class Bate : public Weapon {
private:
    int damage;
    float distance;
public:
    Bate(b2Vec2& attackerPosition, b2Vec2& attackedPosition);
    void attack(WWorm* worm) override;

    ~Bate() override = default;
};