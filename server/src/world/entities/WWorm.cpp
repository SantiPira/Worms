#include "world/entities/WWorm.h"

WWorm::WWorm(b2World* world, uint8_t id, float posX, float posY) {
    m_World = world;
    m_Width = 0.50f; //Valores cargados por config?
    m_Height = 1.0f; //Valores cargados por config?
    b2BodyDef bd;
    bd.position.Set(posX, posY + m_Width);
    bd.type = b2_dynamicBody;
    bd.fixedRotation = true;
    bd.allowSleep = false;
    m_Body = m_World->CreateBody(&bd);
    b2PolygonShape shape;
    shape.SetAsBox(m_Width, m_Height);
    b2FixtureDef fd;
    fd.friction = 0.0f;
    fd.shape = &shape;
    fd.density = 20.0f;
    m_Body->CreateFixture(&fd);

    this->m_Id = id;
    this->m_Position = b2Vec2(0, 0);
    this->m_Velocity = b2Vec2(0, 0);
    this->m_Angle = 0;
    this->m_AngularVelocity = 0;
    this->m_Health = 100; //Valores cargados por config?
    this->m_Ammo = 50;     //Valores cargados por config?
    this->m_Score = 0;
    this->m_IsDead = false;
    this->m_IsFacingRight = true;
    this->m_IsMoving = false;
    this->m_IsJumping = false;
    this->m_IsFalling = false;
    this->m_IsShooting = false;
    this->m_Weapon = Weapon::NO_WEAPON;
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
    this->m_IsDead = isDead;
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
    GameAction move;
    GameAction actionWeapon;
    float posX, posY;
    b2Vec2 velocity = m_Body->GetLinearVelocity();
    if (velocity.x > 0) {
        move = WORM_MOVE_RIGHT;
    } else if (velocity.x < 0) {
        move = WORM_MOVE_LEFT;
    } else if (velocity.y > 0) {
        move = WORM_JUMP;
    } else if (velocity.y < 0) {
        move = WORM_FALL;
    } else {
        move = WORM_MOVE_RIGHT;
    }
//    gameUpdate.player_id = m_Id;
    posX = getPosition().x;
    posY = getPosition().y;

    if (m_Weapon != Weapon::NO_WEAPON) {
        actionWeapon = m_IsAttacking ? GameAction::HAS_WEAPON_AND_ATTACK : GameAction::HAS_WEAPON_AND_NO_ATTACK;
    } else {
        actionWeapon = GameAction::NO_HAS_WEAPON;
    }
    gameUpdate.player_id = m_Id;
    gameUpdate.m_Move = move;
    gameUpdate.x_pos = posX;
    gameUpdate.y_pos = posY;
    gameUpdate.m_Weapon = m_Weapon;
    gameUpdate.m_ActionWeapon = actionWeapon;
    return gameUpdate;
}

void WWorm::jump(b2Vec2 vel) {
    m_Body->ApplyLinearImpulse(vel, m_Body->GetWorldCenter(), true);
    this->m_IsJumping = true;
    this->m_IsMoving = false;
}

void WWorm::stopMove() {
    b2Vec2 vel = b2Vec2(0, 0);
    this->m_Body->SetLinearVelocity(vel);
    this->m_Velocity = vel;
    this->m_IsMoving = false;
    this->m_IsJumping = false;
    this->m_IsFalling = false;
}

void WWorm::attack() {
    std::cout << "Esta atacando en Direction: " << static_cast<int>(m_Dir) << std::endl;
    m_IsAttacking = true;
}

Weapon WWorm::getWeapon() const {
    return this->m_Weapon;
}

void WWorm::setWeapon(Weapon weapon) {
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
