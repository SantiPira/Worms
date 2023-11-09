#pragma once

#include "ActionType.h"

class UserAction {
private:
    ActionType action;
    int idPlayer;
    int8_t param1;
    int8_t param2;
public:
    UserAction(ActionType action, int idPlayer, int8_t param1, int8_t param2);
    UserAction(ActionType action, int idPlayer, int8_t param1);
    UserAction(ActionType action, int idPlayer);
    UserAction();

    [[nodiscard]] ActionType getAction() const;
    [[nodiscard]] int getIdPlayer() const;
    [[nodiscard]] int8_t getParam1() const;
    [[nodiscard]] int8_t getParam2() const;

    UserAction(const UserAction&) = default;
};