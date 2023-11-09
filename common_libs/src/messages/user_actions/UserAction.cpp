#include "messages/user_actions/UserAction.h"

UserAction::UserAction(ActionType action, int idPlayer, int8_t param1, int8_t param2) : action(action),
    idPlayer(idPlayer), param1(param1), param2(param2) {}

UserAction::UserAction(ActionType action, int idPlayer) : action(action), idPlayer(idPlayer), param1(0), param2(0) {}

UserAction::UserAction() : action(ActionType::NONE), idPlayer(0), param1(0), param2(0) {}

UserAction::UserAction(ActionType action, int idPlayer, int8_t param1) : action(action), idPlayer(idPlayer),
    param1(param1), param2(0) {}

ActionType UserAction::getAction() const {
    return action;
}

int UserAction::getIdPlayer() const {
    return idPlayer;
}

int8_t UserAction::getParam1() const {
    return param1;
}

int8_t UserAction::getParam2() const {
    return param2;
}
