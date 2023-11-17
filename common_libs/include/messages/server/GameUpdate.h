#pragma once

#include "GameActionEnum.h"
#include "../user_actions/WeaponID.h"
#include "messages/user_actions/ActionType.h"
#include <unordered_set>


struct GameUpdate {
    uint8_t player_id;
    GameAction m_Move;
    float x_pos;
    float y_pos;
    float width; // 1m
    float height; //1.6m 1920x1080
    WeaponID m_Weapon;
    GameAction m_ActionWeapon;
    uint8_t m_Health;
    Direction  m_Dir;
    GameAction m_SelfCondition;

    GameUpdate() : player_id(0), m_Move(INVALID_ACTION), x_pos(0), y_pos(0), width(0.0f), height(0.0f),
        m_Weapon(NO_WEAPON), m_ActionWeapon(NO_HAS_WEAPON), m_Health(0), m_Dir(Direction::RIGHT),
        m_SelfCondition(GameAction::WORM_NONE) {}

    bool operator==(const GameUpdate& gameUpdate) const {
        return player_id == gameUpdate.player_id && m_Move == gameUpdate.m_Move && x_pos == gameUpdate.x_pos &&
               y_pos == gameUpdate.y_pos && width == gameUpdate.width && height == gameUpdate.height
               && m_Weapon == gameUpdate.m_Weapon && m_ActionWeapon == gameUpdate.m_ActionWeapon
               && m_Health == gameUpdate.m_Health && m_Dir == gameUpdate.m_Dir
               && m_SelfCondition == gameUpdate.m_SelfCondition;
    }
};

struct GameUpdateHash {
    std::size_t operator()(const GameUpdate& gameUpdate) const {
        std::size_t h1 = std::hash<uint8_t>{}(gameUpdate.player_id);
        std::size_t h2 = std::hash<int>{}(static_cast<int>(gameUpdate.m_Move));
        std::size_t h3 = std::hash<float>{}(gameUpdate.x_pos);
        std::size_t h4 = std::hash<float>{}(gameUpdate.y_pos);
        std::size_t h5 = std::hash<float>{}(gameUpdate.width);
        std::size_t h6 = std::hash<float>{}(gameUpdate.height);
        std::size_t h7 = std::hash<int>{}(static_cast<int>(gameUpdate.m_Weapon));
        std::size_t h8 = std::hash<int>{}(static_cast<int>(gameUpdate.m_ActionWeapon));
        std::size_t h9 = std::hash<uint8_t>{}(gameUpdate.m_Health);
        std::size_t h10 = std::hash<int>{}(static_cast<int>(gameUpdate.m_Dir));
        std::size_t h11 = std::hash<int>{}(static_cast<int>(gameUpdate.m_SelfCondition));

        return h1 ^ h2 ^ h3 ^ h4 ^ h5 ^ h6 ^ h7 ^ h8 ^ h9 ^ h10 ^ h11;
    }
};
