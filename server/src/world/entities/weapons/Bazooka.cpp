#include "world/entities/weapons/impl/Bazooka.h"

Bazooka::Bazooka() : damage(1), distance(2.0f) {
    this->m_WeaponId = WeaponID::BAZOOKA;
}

void Bazooka::attack(WWorm *attacker, WWorm *attacked, uint8_t force) {
    attacker->getActionToAnimation()->resetAnimation();
    attacker->getActionToAnimation()->setAction(ActionType::ATTACK, m_WeaponId, 0);
    if (attacked->getId() == attacker->getId()) {
        return;
    }

    // Ángulo para la bazooka
    float angle =  attacker->getWeaponAngle();   //attacker->getWeaponAngle();

    // Crear el proyectil
    b2BodyDef projectileBodyDef;
    projectileBodyDef.type = b2_dynamicBody;

    if (attacker->getDirection() == Direction::LEFT) {
        projectileBodyDef.position.Set(attacker->getPosition().x - 0.5, attacker->getPosition().y + 0.5);
    } else {
        projectileBodyDef.position.Set(attacker->getPosition().x + 0.5, attacker->getPosition().y + 0.5);
    }

    b2Body* projectileBody = attacker->getWorld()->CreateBody(&projectileBodyDef);



     // Crear la forma del proyectil
    b2CircleShape projectileShape;
    projectileShape.m_radius = 0.13f;  // Radio del proyectil


    // Definir las propiedades del proyectil (densidad, fricción, restitución)
    b2FixtureDef projectileFixtureDef;
    projectileFixtureDef.shape = &projectileShape;
    projectileFixtureDef.density = 1.0f;
    projectileFixtureDef.friction = 0.2f;
    projectileFixtureDef.restitution = 0.0f;
    projectileBody->CreateFixture(&projectileFixtureDef);

    b2Vec2 initialForce(cos(angle)*projectileBody->GetMass()*9.8, sin(angle)*projectileBody->GetMass()*9.8);

    if (attacker->getDirection() == Direction::LEFT){
        initialForce.x *= -1;
        initialForce.y *= -1;
    }

    projectileBody->ApplyLinearImpulseToCenter(initialForce, true);

    b2Vec2 projectilePosition = projectileBody->GetPosition();



    if((projectilePosition - attacked->getPosition()).Length() < 3) {
        attacker->setIsAttacking(true);
        attacked->receiveDamage(damage);
    }

    attacker->tieneProyectil = true;
    attacker->proyectil = projectileBody;
}

void Bazooka::setWeaponId(WeaponID weaponId) {
    this->m_WeaponId = weaponId;
}

WeaponID Bazooka::getWeaponId() const {
    return this->m_WeaponId;
}