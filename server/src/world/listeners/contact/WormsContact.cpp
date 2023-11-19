#include "world/listeners/contact/WormsContact.h"

void WormsContact::BeginContact(b2Body* bodyA, b2Body* bodyB) {

    WEntity* entityA = reinterpret_cast<WEntity*>(bodyA->GetUserData().pointer);
    WEntity* entityB = reinterpret_cast<WEntity*>(bodyB->GetUserData().pointer);

    WWorm* wormA = nullptr;
    WWorm* wormB = nullptr;
    if (entityA == nullptr || entityB == nullptr) {
        return;
    }
    if (entityA->getEntityType() == EntitiesType::ENTITY_WORM && entityB->getEntityType() == EntitiesType::ENTITY_WORM) {
        wormA = reinterpret_cast<WWorm*>(bodyA->GetUserData().pointer);
        wormB = reinterpret_cast<WWorm*>(bodyB->GetUserData().pointer);
    }
    if (wormA != nullptr && wormB != nullptr
            && wormA->getEntityType() == EntitiesType::ENTITY_WORM
            && wormB->getEntityType() == EntitiesType::ENTITY_WORM) {
        std::cout << "[COLISION] [WORM-A - ID: [" << static_cast<int>(wormA->getId()) << "]" << std::endl;
        wormA->setVelocity(b2Vec2_zero);
        wormA->getBody()->GetFixtureList()->SetFriction(400.0f);
        wormB->setVelocity(b2Vec2_zero);
        wormB->getBody()->GetFixtureList()->SetFriction(400.0f);

        std::cout << "[COLISION] [WORM-B - ID: [" << static_cast<int>(wormB->getId()) << "]" << std::endl;
    }
}

void WormsContact::EndContact(b2Body* bodyA, b2Body* bodyB) {
    WEntity* entityA = reinterpret_cast<WEntity*>(bodyA->GetUserData().pointer);
    WEntity* entityB = reinterpret_cast<WEntity*>(bodyB->GetUserData().pointer);

    WWorm* wormA = nullptr;
    WWorm* wormB = nullptr;

    if (entityA == nullptr || entityB == nullptr) {
        return;
    }

    if (entityA->getEntityType() == EntitiesType::ENTITY_WORM && entityB->getEntityType() == EntitiesType::ENTITY_WORM) {
        wormA = reinterpret_cast<WWorm*>(bodyA->GetUserData().pointer);
        wormB = reinterpret_cast<WWorm*>(bodyB->GetUserData().pointer);
    }

    if (wormA != nullptr && wormB != nullptr) {
        std::cout << "[COLISION] [WORM-A - ID: [" << static_cast<int>(wormA->getId()) << "]" << std::endl;
        wormA->setVelocity(b2Vec2_zero);
        wormA->getBody()->GetFixtureList()->SetFriction(0.0f);
        wormB->setVelocity(b2Vec2_zero);
        wormB->getBody()->GetFixtureList()->SetFriction(0.0f);

        std::cout << "[COLISION] [WORM-B - ID: [" << static_cast<int>(wormB->getId()) << "]" << std::endl;
    }
}
