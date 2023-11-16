#pragma once

#include "GameActionEnum.h"
#include "../user_actions/Weapon.h"
#include <unordered_set>


struct GameUpdate {
    uint8_t player_id;
    GameAction m_Move;
    float x_pos;
    float y_pos;
    float width;
    float height;
    Weapon m_Weapon;
    GameAction m_ActionWeapon;
    uint8_t m_Health;

    GameUpdate() : player_id(0), m_Move(INVALID_ACTION), x_pos(0), y_pos(0), width(0.0f), height(0.0f),
        m_Weapon(NO_WEAPON), m_ActionWeapon(NO_HAS_WEAPON), m_Health(0) {}

    GameUpdate(uint8_t player_id, GameAction action, float x_pos, float y_pos, float width, float height,
               uint8_t health) : player_id(player_id), m_Move(action), x_pos(x_pos), y_pos(y_pos), width(width), height(height),
            m_Weapon(NO_WEAPON), m_ActionWeapon(NO_HAS_WEAPON), m_Health(health) {}

    GameUpdate(uint8_t player_id, GameAction action, float x_pos, float y_pos, float width, float height,
               Weapon weapon, uint8_t health) : player_id(player_id), m_Move(action), x_pos(x_pos), y_pos(y_pos), width(width), height(height),
               m_Weapon(weapon), m_ActionWeapon(HAS_WEAPON_AND_NO_ATTACK), m_Health(health) {}

    GameUpdate(uint8_t player_id, GameAction action, float x_pos, float y_pos, float width, float height, Weapon weapon,
               GameAction actionWeapon, uint8_t health) : player_id(player_id), m_Move(action), x_pos(x_pos), y_pos(y_pos),
               width(width), height(height), m_Weapon(weapon), m_ActionWeapon(actionWeapon), m_Health(health) {}

    bool operator==(const GameUpdate& gameUpdate) const {
        return player_id == gameUpdate.player_id && m_Move == gameUpdate.m_Move && x_pos == gameUpdate.x_pos &&
               y_pos == gameUpdate.y_pos && width == gameUpdate.width && height == gameUpdate.height
               && m_Weapon == gameUpdate.m_Weapon && m_ActionWeapon == gameUpdate.m_ActionWeapon
               && m_Health == gameUpdate.m_Health;
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

        return h1 ^ h2 ^ h3 ^ h4 ^ h5 ^ h6 ^ h7 ^ h8 ^ h9;
    }
};
