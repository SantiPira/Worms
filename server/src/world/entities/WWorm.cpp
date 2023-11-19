#include "world/entities/WWorm.h"

WWorm::WWorm(b2World* world, uint8_t id, float posX, float posY, bool isFacingRight, uint16_t wormCategory,
             const std::vector<uint16_t>& categories) {
    m_World = world;
    m_Width = 0.50f; //Valores cargados por config?
    m_Height = 0.80f; //Valores cargados por config?
    b2BodyDef bd;
    bd.position.Set(posX, posY);
    bd.type = b2_dynamicBody;
    bd.fixedRotation = true;
    bd.allowSleep = false;
    bd.userData.pointer = reinterpret_cast<uintptr_t>(this);
    //store "Worm Entity" in body's user data
    m_Body = m_World->CreateBody(&bd);
    b2PolygonShape shape;
    shape.SetAsBox(m_Width, m_Height);
    b2FixtureDef fd;
    fd.friction = 0.0f;
    fd.shape = &shape;
    fd.density = 20.0f;
    m_Body->CreateFixture(&fd);
    b2Filter filter;
    m_WormCategory = wormCategory;
    filter.categoryBits = m_WormCategory;
    for (unsigned short category : categories) {
        filter.maskBits |= category;
    }
    m_Body->GetFixtureList()->SetFilterData(filter);
    m_EntityType = EntitiesType::ENTITY_WORM;
    //world->SetContactListener(&m_WormsContact);

    this->m_Id = id;
    this->m_Position = b2Vec2_zero;
    this->m_Velocity = b2Vec2_zero;
    this->m_Angle = 0;
    this->m_AngularVelocity = 0;
    this->m_Health = 100; //Valores cargados por config?
    this->m_Ammo = 50;     //Valores cargados por config?
    this->m_Score = 0;
    this->m_IsDead = false;
    this->m_IsMoving = false;
    this->m_IsJumping = false;
    this->m_IsFalling = false;
    this->m_IsShooting = false;
    this->m_Weapon = WeaponID::NO_WEAPON;
    this->m_IsFacingRight = isFacingRight;
    this->m_Dir = isFacingRight ? Direction::RIGHT : Direction::LEFT;
    this->m_SelfCondtion = GameAction::WORM_NONE;
}

[[maybe_unused]] uint8_t WWorm::getId() const {
    return m_Id;
}

b2Body *WWorm::getBody() const {
    return m_Body;
}

b2Vec2 WWorm::getPosition() const {
    return m_Body->GetPosition();
}

b2Vec2 WWorm::getVelocity() const {
    return m_Body->GetLinearVelocity();
}

float WWorm::getAngle() const {
    return m_Body->GetAngle();
}

float WWorm::getAngularVelocity() const {
    return m_Body->GetAngularVelocity();
}

int32 WWorm::getHealth() const {
    return m_Health;
}

int32 WWorm::getAmmo() const {
    return m_Ammo;
}

int32 WWorm::getScore() const {
    return m_Score;
}

bool WWorm::getIsDead() const {
    return m_IsDead;
}

bool WWorm::getIsFacingRight() const {
    return m_IsFacingRight;
}

bool WWorm::getIsMoving() const {
    return m_IsMoving;
}

bool WWorm::getIsJumping() const {
    return m_IsJumping;
}

bool WWorm::getIsFalling() const {
    return m_IsFalling;
}

bool WWorm::getIsShooting() const {
    return m_IsShooting;
}

void WWorm::setPosition(b2Vec2 position) {
    this->m_Position = position;
}

void WWorm::setVelocity(b2Vec2 velocity) {
    this->m_Velocity = velocity;
    this->m_Body->SetLinearVelocity(m_Velocity);
    this->m_IsMoving = true;
}

void WWorm::setAngle(float angle) {
    this->m_Angle = angle;
}

void WWorm::setAngularVelocity(float angularVelocity) {
    this->m_AngularVelocity = angularVelocity;
}

void WWorm::setHealth(int32 health) {
    this->m_Health = health;
}

void WWorm::setAmmo(int32 ammo) {
    this->m_Ammo = ammo;
}

void WWorm::setScore(int32 score) {
    this->m_Score = score;
}

void WWorm::setIsDead(bool isDead) {
    this->m_Health = 0;
    this->m_IsDead = isDead;
    this->m_SelfCondtion = GameAction::WORM_DIE;
}

void WWorm::setIsFacingRight(bool isFacingRight) {
    this->m_IsFacingRight = isFacingRight;
}

void WWorm::setIsMoving(bool isMoving) {
    this->m_IsMoving = isMoving;
}

void WWorm::setIsJumping(bool isJumping) {
    this->m_IsJumping = isJumping;
}

void WWorm::setIsFalling(bool isFalling) {
    this->m_IsFalling = isFalling;
}

void WWorm::setIsShooting(bool isShooting) {
    this->m_IsShooting = isShooting;
}

GameUpdate WWorm::getUpdate() const {
    GameUpdate gameUpdate;
    GameAction move = WORM_MOVE_RIGHT;
    //GameAction actionWeapon;
    float posX, posY;
    b2Vec2 velocity = m_Body->GetLinearVelocity();
    if (velocity.x > 0) {
        move = WORM_MOVE_RIGHT;
    }
    if (velocity.x < 0) {
        move = WORM_MOVE_LEFT;
    }
    if (velocity.y > 0 || (velocity.y > 0 && m_IsMoving)) {
        move = WORM_JUMP;
    }
    if (velocity.y < 0) {
        move = WORM_JUMP;
    }

    posX = getPosition().x;
    posY = getPosition().y;

    gameUpdate.player_id = m_Id;
    gameUpdate.m_Move = move;
    gameUpdate.x_pos = posX;
    gameUpdate.y_pos = posY;
    gameUpdate.m_Weapon = m_Weapon;
    gameUpdate.m_ActionWeapon = m_IsAttacking ? GameAction::HAS_WEAPON_AND_ATTACK : GameAction::HAS_WEAPON_AND_NO_ATTACK;
    gameUpdate.width = m_Width * 2;
    gameUpdate.height = m_Height * 2;
    gameUpdate.m_Health = m_Health;
    gameUpdate.m_Dir = m_Dir;
    gameUpdate.m_SelfCondition = m_SelfCondtion;
    gameUpdate.m_TimeDuration = m_SelfCondtion == GameAction::WORM_DIE ? 3.0 : 0.0;
    return gameUpdate;
}

void WWorm::jump(b2Vec2 vel) {
    m_Body->ApplyLinearImpulse(vel, m_Body->GetWorldCenter(), true);
    this->m_IsJumping = true;
}

void WWorm::stopMove() {
    b2Vec2 vel = b2Vec2_zero;
    this->m_Body->SetLinearVelocity(vel);
    this->m_Velocity = vel;
    this->m_IsMoving = false;
    this->m_IsJumping = false;
    this->m_IsFalling = false;
}

void WWorm::attack() {
    WeaponFactory weaponFactory;
    m_IsAttacking = true;
    b2Vec2 attackerPosition = m_Body->GetPosition();
    for (b2Body* worm = m_World->GetBodyList(); worm; worm = worm->GetNext()) {
        auto* w = reinterpret_cast<WWorm*>(worm->GetUserData().pointer);
        if (w != nullptr && w->getId() != m_Id) {
            b2Vec2 position = w->getBody()->GetPosition();
            std::unique_ptr<Weapon> weaponPtr(weaponFactory.createWeapon(m_Weapon, attackerPosition, position));
            weaponPtr->attack(w);
        }
    }
}

WeaponID WWorm::getWeapon() const {
    return this->m_Weapon;
}

void WWorm::setWeapon(WeaponID weapon) {
    this->m_Weapon = weapon;
}

Direction WWorm::getDirection() const {
    return this->m_Dir;
}

void WWorm::setDirection(Direction dir) {
    this->m_Dir = dir;
}

bool WWorm::getIsAttacking() const {
    return this->m_IsAttacking;
}

void WWorm::setIsAttacking(bool isAttacking) {
    this->m_IsAttacking = isAttacking;
}

void WWorm::receiveDamage(int damage) {
    this->m_SelfCondtion = GameAction::WORM_ATTACKED;
    this->m_Health -= damage;
    if (this->m_Health <= 0) {
        this->m_IsDead = true;
        this->m_SelfCondtion = GameAction::WORM_DIE;
    }
}

GameAction WWorm::getSelfCondition() const {
    return this->m_SelfCondtion;
}

void WWorm::setSelfCondition(GameAction selfCondition) {
    this->m_SelfCondtion = selfCondition;
}

WWorm::WWorm() : m_Id(0xFF){
}

EntitiesType WWorm::getEntityType() {
    return m_EntityType;
}

