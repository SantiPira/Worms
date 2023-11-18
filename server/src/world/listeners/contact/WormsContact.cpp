#include "world/listeners/contact/WormsContact.h"

void WormsContact::BeginContact(b2Contact* contact) {
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    b2Body* bodyA = fixtureA->GetBody();
    b2Body* bodyB = fixtureB->GetBody();

    WWorm* wormA = reinterpret_cast<WWorm*>(bodyA->GetUserData().pointer);
    WWorm* wormB = reinterpret_cast<WWorm*>(bodyB->GetUserData().pointer);

    if (wormA != nullptr && wormB != nullptr) {
        std::cout << "[COLISION] [WORM-A - ID: [" << static_cast<int>(wormA->getId()) << "]" << std::endl;
        wormA->setVelocity(b2Vec2_zero);
        wormA->getBody()->GetFixtureList()->SetFriction(400.0f);
        wormB->setVelocity(b2Vec2_zero);
        wormB->getBody()->GetFixtureList()->SetFriction(400.0f);


        std::cout << "[COLISION] [WORM-B - ID: [" << static_cast<int>(wormB->getId()) << "]" << std::endl;
    }
}

void WormsContact::EndContact(b2Contact *contact) {
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    b2Body* bodyA = fixtureA->GetBody();
    b2Body* bodyB = fixtureB->GetBody();

    WWorm* wormA = reinterpret_cast<WWorm*>(bodyA->GetUserData().pointer);
    WWorm* wormB = reinterpret_cast<WWorm*>(bodyB->GetUserData().pointer);

    if (wormA != nullptr && wormB != nullptr) {
        std::cout << "[COLISION] [WORM-A - ID: [" << static_cast<int>(wormA->getId()) << "]" << std::endl;
        wormA->setVelocity(b2Vec2_zero);
        wormA->getBody()->GetFixtureList()->SetFriction(0.0f);
        wormB->setVelocity(b2Vec2_zero);
        wormB->getBody()->GetFixtureList()->SetFriction(0.0f);

        std::cout << "[COLISION] [WORM-B - ID: [" << static_cast<int>(wormB->getId()) << "]" << std::endl;
    }
}
