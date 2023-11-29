#include "world/entities/weapons/impl/Bazooka.h"

Bazooka::Bazooka() : damage(100), distance(2.0f) {
    this->m_WeaponId = WeaponID::BAZOOKA;
}

void Bazooka::attack(WWorm *attacker, WWorm *attacked, uint8_t force) {
    if (attacked->getId() == attacker->getId()) {
        return;
    }
    attacker->getActionToAnimation()->resetAnimation();
    attacker->getActionToAnimation()->setAction(ActionType::ATTACK, m_WeaponId, 0);

    /*
    float distanceBetween = b2Distance(attacker->getPosition(), attacked->getPosition());

    if(distanceBetween > distance) {
        return;
    }
    */


    // Ángulo para la bazooka
    float angle =  0.0f;   //attacker->getWeaponAngle();

    // Crear el proyectil
    b2BodyDef projectileBodyDef;
    projectileBodyDef.type = b2_dynamicBody;
    projectileBodyDef.position.Set(attacker->getPosition().x, attacker->getPosition().y);
    b2Body* projectileBody = attacker->getWorld()->CreateBody(&projectileBodyDef);

     // Crear la forma del proyectil
    b2CircleShape projectileShape;
    projectileShape.m_radius = 0.1f;  // Radio del proyectil


    // Definir las propiedades del proyectil (densidad, fricción, restitución)
    b2FixtureDef projectileFixtureDef;
    projectileFixtureDef.shape = &projectileShape;
    projectileFixtureDef.density = 1.0f;
    projectileFixtureDef.friction = 0.2f;
    projectileFixtureDef.restitution = 0.0f;
    projectileBody->CreateFixture(&projectileFixtureDef);


    // Calcular la velocidad inicial del proyectil
    float projectileSpeed = 10.0f;  // Puedes ajustar la velocidad según tus necesidades
    b2Vec2 projectileVelocity(projectileSpeed * cos(angle), projectileSpeed * sin(angle));

    // Aplicar la velocidad inicial al proyectil
    projectileBody->SetLinearVelocity(projectileVelocity);

    b2Vec2 projectilePosition = projectileBody->GetPosition();

    if(projectilePosition == attacked->getPosition()) {
        attacked->receiveDamage(damage);
    }
}

void Bazooka::setWeaponId(WeaponID weaponId) {
    this->m_WeaponId = weaponId;
}

WeaponID Bazooka::getWeaponId() const {
    return this->m_WeaponId;
}