#pragma once

#include "GameActionEnum.h"
#include "../user_actions/WeaponID.h"
#include "messages/user_actions/ActionType.h"
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

    GameUpdate() : player_id(0), x_pos(0), y_pos(0), width(0.0f), height(0.0f), m_TimeDuration(0.0f),
    m_Movement(INVALID_ACTION), m_Weapon(NO_WEAPON), m_IsAttacking(false), m_Health(0), m_Dir(Direction::RIGHT),
    m_SelfCondition(GameAction::WORM_NONE) {}

    bool operator==(const GameUpdate& gameUpdate) const {
        return player_id == gameUpdate.player_id && m_Movement == gameUpdate.m_Movement && x_pos == gameUpdate.x_pos &&
               y_pos == gameUpdate.y_pos && width == gameUpdate.width && height == gameUpdate.height
               && m_Weapon == gameUpdate.m_Weapon && m_IsAttacking == gameUpdate.m_IsAttacking
               && m_Health == gameUpdate.m_Health && m_Dir == gameUpdate.m_Dir
               && m_SelfCondition == gameUpdate.m_SelfCondition && m_TimeDuration == gameUpdate.m_TimeDuration;
    }
};

struct GameUpdateHash {
    std::size_t operator()(const GameUpdate& gameUpdate) const {
        std::size_t h1 = std::hash<uint8_t>{}(gameUpdate.player_id);
        std::size_t h2 = std::hash<int>{}(static_cast<int>(gameUpdate.m_Movement));
        std::size_t h3 = std::hash<float>{}(gameUpdate.x_pos);
        std::size_t h4 = std::hash<float>{}(gameUpdate.y_pos);
        std::size_t h5 = std::hash<float>{}(gameUpdate.width);
        std::size_t h6 = std::hash<float>{}(gameUpdate.height);
        std::size_t h7 = std::hash<int>{}(static_cast<int>(gameUpdate.m_Weapon));
        std::size_t h8 = std::hash<int>{}(static_cast<int>(gameUpdate.m_IsAttacking));
        std::size_t h9 = std::hash<uint8_t>{}(gameUpdate.m_Health);
        std::size_t h10 = std::hash<int>{}(static_cast<int>(gameUpdate.m_Dir));
        std::size_t h11 = std::hash<int>{}(static_cast<int>(gameUpdate.m_SelfCondition));
        std::size_t h12 = std::hash<double>{}(gameUpdate.m_TimeDuration);

        return h1 ^ h2 ^ h3 ^ h4 ^ h5 ^ h6 ^ h7 ^ h8 ^ h9 ^ h10 ^ h11 ^ h12;
    }
};
