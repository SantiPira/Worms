#include "world/listeners/contact/BazookaContact.h"

void BazookaContact::BeginContact(b2Body* bodyA, b2Body* bodyB) {

    WEntity* entityA = reinterpret_cast<WEntity*>(bodyA->GetUserData().pointer);
    WEntity* entityB = reinterpret_cast<WEntity*>(bodyB->GetUserData().pointer);

    WWorm* worm;
    WProyectile* proyectile;

    if (entityA == nullptr || entityB == nullptr) {
        return;
    }

    if ((entityA->getEntityType() == EntitiesType::ENTITY_PROYECTILE && entityB->getEntityType() == EntitiesType::ENTITY_WORM) ||
        (entityA->getEntityType() == EntitiesType::ENTITY_WORM && entityB->getEntityType() == EntitiesType::ENTITY_PROYECTILE)) {

        entityA->getEntityType();

        std::cout << "[PROYECTILE COLLIDE]" << std::endl;
        if (entityA->getEntityType() == EntitiesType::ENTITY_WORM) {
            worm = reinterpret_cast<WWorm*>(bodyA->GetUserData().pointer);
            proyectile = reinterpret_cast<WProyectile*>(bodyB->GetUserData().pointer);
        } else {
            worm = reinterpret_cast<WWorm*>(bodyB->GetUserData().pointer);
            proyectile = reinterpret_cast<WProyectile*>(bodyA->GetUserData().pointer);
        }
                
        float distance = std::sqrt(std::pow(worm->getPosition().x - proyectile->getPositionX(), 2) +
                                std::pow(worm->getPosition().y - proyectile->getPositionY(), 2));

        std::cout << "DISTANCIA: " << distance << std::endl;

        if(distance <= proyectile->getRadius() && worm->getHealth() > 50){
            worm->receiveDamage(50);
        } else if (distance <= proyectile->getRadius() && worm->getHealth() <= 50) {
            worm->setIsDead();
        }

        proyectile->SetCollide();



        std::cout << "COLIISIONO" << std::endl;
    }

    //std::cout <<"No hubo colision" << std::endl;

}

void BazookaContact::EndContact(b2Body* bodyA, b2Body* bodyB) {
    //std::cout << "[PROYECTILE END COLLIDE]" << std::endl;



}