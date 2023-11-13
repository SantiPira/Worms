#pragma once

#include "GameActionEnum.h"
#include "../user_actions/Weapon.h"

struct GameUpdate {
    uint8_t player_id;
    GameAction m_Move;
    float x_pos;
    float y_pos;
    Weapon m_Weapon;
    GameAction m_ActionWeapon;

    GameUpdate() : player_id(0), m_Move(WORM_NONE), x_pos(0), y_pos(0), m_Weapon(NO_WEAPON),
        m_ActionWeapon(NO_HAS_WEAPON) {}

    GameUpdate(uint8_t player_id, GameAction action, float x_pos, float y_pos) :
            player_id(player_id), m_Move(action), x_pos(x_pos), y_pos(y_pos), m_Weapon(NO_WEAPON),
            m_ActionWeapon(NO_HAS_WEAPON) {}

    GameUpdate(uint8_t player_id, GameAction action, float x_pos, float y_pos, Weapon weapon) :
        player_id(player_id), m_Move(action), x_pos(x_pos), y_pos(y_pos), m_Weapon(weapon),
        m_ActionWeapon(HAS_WEAPON_AND_NO_ATTACK) {}

    GameUpdate(uint8_t player_id, GameAction action, float x_pos, float y_pos, Weapon weapon, GameAction actionWeapon) :
            player_id(player_id), m_Move(action), x_pos(x_pos), y_pos(y_pos), m_Weapon(weapon),
            m_ActionWeapon(actionWeapon) {}

};
