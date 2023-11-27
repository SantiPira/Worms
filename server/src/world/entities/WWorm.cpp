#include "world/entities/WWorm.h"

WWorm::WWorm() : m_Id(0xFF) {}

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
    m_Body = m_World->CreateBody(&bd);
    b2PolygonShape shape;
    shape.SetAsBox(m_Width, m_Height);
    b2FixtureDef fd;
    fd.friction = 0.0f;
    fd.shape = &shape;
    fd.density = 20.0f;
    fd.restitution = 0.0f;
    m_Body->CreateFixture(&fd);
    b2Filter filter;
    m_WormCategory = wormCategory;
    filter.categoryBits = m_WormCategory;
    for (unsigned short category : categories) {
        filter.maskBits |= category;
    }
    m_Body->GetFixtureList()->SetFilterData(filter);
    m_EntityType = EntitiesType::ENTITY_WORM;
    m_WasChanged = true;

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
    this->m_SelfCondition = GameAction::WORM_IDLE;
    m_ActionToAnimation = ActionToAnimation();
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
    return this->m_Body->GetLinearVelocity().x != 0 || this->m_Body->GetLinearVelocity().y != 0;
}


bool WWorm::getIsJumping() const {
    return this->m_Body->GetLinearVelocity().y > 0;
}

bool WWorm::getIsFalling() const {
    return this->m_Body->GetLinearVelocity().y < 0;
}

bool WWorm::getIsShooting() const {
    return m_IsShooting;
}

void WWorm::setPosition(b2Vec2 position) {
    this->m_Position = position;
}

void WWorm::setVelocity(b2Vec2 velocity) {
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

void WWorm::setIsDead() {
    m_ActionToAnimation.resetAnimation();
    m_ActionToAnimation.setAction(ActionType::DYING);
    this->setVelocity(b2Vec2_zero);
    this->m_Health = 0;
    this->m_IsDead = true;
    this->m_SelfCondition = GameAction::WORM_DIE;
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

GameUpdate WWorm::getUpdate(bool wormChanged) {
    GameUpdate currentState;
    currentState.player_id = m_Id;
    currentState.x_pos = getPosition().x;
    currentState.y_pos = getPosition().y;
    currentState.width = m_Width * 2;
    currentState.height = m_Height * 2;
    currentState.m_Health = m_Health;
    currentState.m_Dir = m_Dir;
    currentState.m_Weapon = m_Weapon;
    currentState.m_IsAttacking = m_IsAttacking;
    currentState.m_Movement = getMovement();
    currentState.m_VelocityX = getVelocity().x;
    currentState.m_VelocityY = getVelocity().y;
    currentState.m_CurrentSprite = m_ActionToAnimation.getCurrentSprite(this);

    if (currentState != m_PreviousState) {
        wormChanged = true;
        m_PreviousState = currentState;
    }

    if(wormChanged) {
        m_WasChanged = false;
        return currentState;
    }

    return {};
}

void WWorm::jump() {
    m_CurrentActionType = ActionType::JUMP;
    b2Vec2 vel = this->getVelocity();
    float epsilon = 0.1f;
    if (std::abs(vel.y) < epsilon) {
        m_ActionToAnimation.resetAnimation();
        m_ActionToAnimation.setAction(m_CurrentActionType);
        float impulse = this->getBody()->GetMass() * 5;
        vel.y = impulse;
        m_Body->ApplyLinearImpulse(vel, m_Body->GetWorldCenter(), true);
        this->m_IsJumping = true;
    }
}

void WWorm::stopMove() {
    m_CurrentActionType = ActionType::STOP_MOVE;
    m_ActionToAnimation.resetAnimation();
    m_ActionToAnimation.setAction(ActionType::STOP_MOVE);
    b2Vec2 vel = b2Vec2_zero;
    this->m_Body->SetLinearVelocity(vel);
    this->m_Velocity = vel;
    m_IsMoving = false;
}

void WWorm::attack(uint8_t force) {
    m_CurrentActionType = ActionType::ATTACK;
    if (m_Weapon != WeaponID::NO_WEAPON) {
        WeaponFactory weaponFactory;
        for (b2Body* entity = m_World->GetBodyList(); entity; entity = entity->GetNext()) {
            auto* wentity = reinterpret_cast<WEntity*>(entity->GetUserData().pointer);
            if (wentity != nullptr && wentity->getEntityType() == EntitiesType::ENTITY_WORM) {
                auto* w = reinterpret_cast<WWorm*>(entity->GetUserData().pointer);
                std::unique_ptr<Weapon> weaponPtr(weaponFactory.createWeapon(m_Weapon));
                weaponPtr->attack(this, w, force);
            }
        }
    }
}

WeaponID WWorm::getWeapon() const {
    return this->m_Weapon;
}

void WWorm::setWeapon(WeaponID weapon, ActionType actionType) {
    m_ActionToAnimation.resetAnimation();
    m_ActionToAnimation.setAction(actionType, weapon);
    this->m_Weapon = weapon;
    m_CurrentActionType = actionType;
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
    m_ActionToAnimation.resetAnimation();
    m_ActionToAnimation.setAction(ActionType::ATTACKED);
    if (damage >= m_Health) {
        m_Health = 0;
        m_ActionToAnimation.resetAnimation();
        m_ActionToAnimation.setAction(ActionType::DYING);
    } else {
        m_Health -= damage;
    }
}

GameAction WWorm::getSelfCondition() const {
    return this->m_SelfCondition;
}

void WWorm::setSelfCondition(GameAction selfCondition) {
    this->m_SelfCondition = selfCondition;
}

EntitiesType WWorm::getEntityType() {
    return m_EntityType;
}

void WWorm::setWeaponAngle(float angle, ActionType actionType) {
    m_CurrentActionType = actionType;
    this->m_WeaponAngle = angle;
}

float WWorm::getWeaponAngle() const {
    return this->m_WeaponAngle;
}

void WWorm::move(Direction direction) {
    if (!m_IsInContactWithWWorm || (m_IsInContactWithWWorm && direction != m_Dir)) {
        m_ActionToAnimation.resetAnimation();
        m_ActionToAnimation.setAction(ActionType::MOVE);
        m_CurrentActionType = ActionType::MOVE;
        m_IsMoving = true;
        float velocity;
        direction == Direction::LEFT ? velocity = -1.0 : velocity = 1.0;
        this->m_Dir = direction;
        b2Vec2 vel = b2Vec2(velocity, 0);
        if (m_Weapon != WeaponID::NO_WEAPON) {
            m_Weapon = WeaponID::NO_WEAPON;
        }
        this->m_Velocity = vel;
        this->m_Body->SetLinearVelocity(vel);
    }
}

GameAction WWorm::getMovement() {
    GameAction move = WORM_IDLE;
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
    return move;
}

void WWorm::resetWormStatus() {
    //if (m_CurrentActionType == ActionType::MOVE || m_CurrentActionType == ActionType::JUMP) {
        m_IsAttacking = false;
        m_IsShooting = false;
        m_IsJumping = false;
        m_IsFalling = false;
        m_IsMoving = false;
        m_IsFacingRight = false;
        m_Weapon = WeaponID::NO_WEAPON;
        m_SelfCondition = m_SelfCondition == WORM_DIE ? WORM_DIE : WORM_IDLE;
        m_WeaponAngle = 0;
        stopMove();
        m_ActionToAnimation.resetAnimation();
        m_ActionToAnimation.setAction(getIsDead() ? ActionType::DYING : ActionType::NONE);
   // }
}

void WWorm::setWasChanged(bool wasChanged) {
    m_WasChanged = wasChanged;
}

bool WWorm::getWasChanged() const {
    return m_WasChanged;
}

GameUpdate WWorm::getPreviousState() const {
    return m_PreviousState;
}

float WWorm::getWidth() const {
    return m_Width;
}

float WWorm::getHeight() const {
    return m_Height;
}

bool WWorm::getIsInContactWithAnotherWorm() const {
    return m_IsInContactWithWWorm;
}

void WWorm::setIsInContactWithAnotherWorm(bool isInContactWithAnotherWorm) {
    m_IsInContactWithWWorm = isInContactWithAnotherWorm;
}

ActionToAnimation *WWorm::getActionToAnimation() {
    return &m_ActionToAnimation;
}

void WWorm::unSetWeapon() {
    m_ActionToAnimation.resetAnimation();
    m_ActionToAnimation.setAction(ActionType::UNSET_WEAPON, m_Weapon, ActionWeaponType::ACTION_WEAPON_TYPE_UNSET_WEAPON);
    m_Weapon = WeaponID::NO_WEAPON;
    m_CurrentActionType = ActionType::UNSET_WEAPON;
}

