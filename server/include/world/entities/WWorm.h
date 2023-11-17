#pragma once

#include "../../../../Box2D/include/box2d/box2d.h"
#include "messages/server/GameUpdate.h"
#include "world/entities/weapons/WeaponFactory.h"
#include "messages/user_actions/ActionType.h"
#include <iostream>
#include <memory>

class WWorm {
private:
    uint8_t m_Id;
    b2World* m_World;
    b2Body* m_Body;
    float m_Width;
    float m_Height;
    b2Vec2 m_Position{};
    b2Vec2 m_Velocity{};
    float m_Angle;
    float m_AngularVelocity;
    int32 m_Health;
    int32 m_Ammo;
    int32 m_Score;
    bool m_IsDead;
    bool m_IsFacingRight;
    bool m_IsMoving;
    bool m_IsJumping;
    bool m_IsFalling;
    bool m_IsShooting;
    GameAction m_SelfCondtion;
    WeaponID m_Weapon;
    Direction m_Dir;
    bool m_IsAttacking;

public:
    WWorm(b2World* world, uint8_t id, float posX, float posY, bool isFacingRight);

    [[maybe_unused]] [[nodiscard]] uint8_t getId() const;
    [[nodiscard]] b2Body* getBody() const;
    [[nodiscard]] b2Vec2 getPosition() const;
    [[nodiscard]] b2Vec2 getVelocity() const;
    [[nodiscard]] float getAngle() const;
    [[nodiscard]] float getAngularVelocity() const;
    [[nodiscard]] int32 getHealth() const;
    [[nodiscard]] int32 getAmmo() const;
    [[nodiscard]] int32 getScore() const;
    [[nodiscard]] bool getIsDead() const;
    [[nodiscard]] bool getIsFacingRight() const;
    [[nodiscard]] bool getIsMoving() const;
    [[nodiscard]] bool getIsJumping() const;
    [[nodiscard]] bool getIsFalling() const;
    [[nodiscard]] bool getIsShooting() const;
    [[nodiscard]] WeaponID getWeapon() const;
    [[nodiscard]] Direction getDirection() const;
    [[nodiscard]] bool getIsAttacking() const;
    [[nodiscard]] GameAction getSelfCondition() const;

    void setPosition(b2Vec2 position);
    void setVelocity(b2Vec2 velocity);
    void setAngle(float angle);
    void setAngularVelocity(float angularVelocity);
    void setHealth(int32 health);
    void setAmmo(int32 ammo);
    void setScore(int32 score);
    void setIsDead(bool isDead);
    void setIsFacingRight(bool isFacingRight);
    void setIsMoving(bool isMoving);
    void setIsJumping(bool isJumping);
    void setIsFalling(bool isFalling);
    void setIsShooting(bool isShooting);
    void setWeapon(WeaponID weapon);
    void setDirection(Direction dir);
    void setIsAttacking(bool isAttacking);
    void setSelfCondition(GameAction selfCondition);

    [[nodiscard]] GameUpdate getUpdate() const;

    void jump(b2Vec2 vel);

    void stopMove();

    void attack();

    void receiveDamage(int damage);

};