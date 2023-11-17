#pragma once

#include "ActionType.h"
#include "WeaponID.h"

class UserAction {
private:
    ActionType m_Action;
    int m_IdPlayer;
    uint8_t m_Param1;
    uint8_t m_Param2;
public:
    UserAction(ActionType action, int idPlayer, uint8_t param1, uint8_t param2);
    UserAction(ActionType action, int idPlayer, uint8_t param1);
    UserAction(ActionType action, int idPlayer);
    UserAction();

    [[nodiscard]] ActionType getAction() const;
    [[nodiscard]] int getIdPlayer() const;
    [[nodiscard]] uint8_t getParam1() const;
    [[nodiscard]] uint8_t getParam2() const;

    void setAction(ActionType actionType);
    void setIdPlayer(int idPlayer);
    void setParam1(uint8_t param1);
    void setParam2(uint8_t param2);


    ~UserAction() = default;

    UserAction(const UserAction&) = default;
};