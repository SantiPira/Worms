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
    if (wormA != nullptr && wormB != nullptr) {
        std::cout << "[BEGIN WORM COLLIDE]" << std::endl;
        if (wormA->getIsAttacking() || wormB->getIsAttacking()) {
            return;
        }
        wormA->getBody()->SetAwake(false);
        wormB->getBody()->SetAwake(false);
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
        if (wormA->getIsAttacking() || wormB->getIsAttacking()) {
            return;
        }
        wormA->getBody()->SetAwake(true);
        wormB->getBody()->SetAwake(true);
    }
}
