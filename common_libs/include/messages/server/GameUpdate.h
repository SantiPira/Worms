#pragma once

#include "GameActionEnum.h"
#include "../user_actions/WeaponID.h"
#include "messages/user_actions/ActionType.h"
#include "messages/sprites/SpritesEnum.h"
#include <unordered_set>

struct GameUpdate {
    uint8_t player_id;
    float x_pos;
    float y_pos;
    float width;
    float height;
    double m_TimeDuration;

    GameAction m_Movement;
    WeaponID m_Weapon;
    bool m_IsAttacking;
    uint8_t m_Health;
    Direction  m_Dir;
    GameAction m_SelfCondition;
    float m_VelocityX;
    float m_VelocityY;
    SpritesEnum m_CurrentSprite;

    GameUpdate() : player_id(0), x_pos(0), y_pos(0), width(0.0f), height(0.0f), m_TimeDuration(0.0f),
    m_Movement(INVALID_ACTION), m_Weapon(NO_WEAPON), m_IsAttacking(false), m_Health(0), m_Dir(Direction::RIGHT),
    m_SelfCondition(GameAction::WORM_NONE), m_VelocityX(0.0f), m_VelocityY(0.0f), m_CurrentSprite(SPRITE_WACCUSE_IDLE) {}

    bool operator!=(const GameUpdate& other) const;
};
