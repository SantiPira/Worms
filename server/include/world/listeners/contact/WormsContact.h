#pragma once

#include "../../../../../Box2D/include/box2d/box2d.h"
#include "world/entities/WWorm.h"

class WormsContact : public b2ContactListener {
public:
    void BeginContact(b2Contact* contact) override;
    void EndContact(b2Contact* contact) override;
};