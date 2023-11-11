#include "messages/user_actions/UserAction.h"

UserAction::UserAction(ActionType action, int idPlayer, int8_t param1, int8_t param2) : m_Action(action),
    m_IdPlayer(idPlayer), m_Param1(param1), m_Param2(param2) {}

UserAction::UserAction(ActionType action, int idPlayer) : m_Action(action), m_IdPlayer(idPlayer), m_Param1(0),
    m_Param2(0) {}

UserAction::UserAction() : m_Action(ActionType::NONE), m_IdPlayer(0), m_Param1(0), m_Param2(0) {}

UserAction::UserAction(ActionType action, int idPlayer, int8_t param1) : m_Action(action), m_IdPlayer(idPlayer),
    m_Param1(param1), m_Param2(0) {}

ActionType UserAction::getAction() const {
    return m_Action;
}

int UserAction::getIdPlayer() const {
    return m_IdPlayer;
}

int8_t UserAction::getParam1() const {
    return m_Param1;
}

int8_t UserAction::getParam2() const {
    return m_Param2;
}

void UserAction::setAction(ActionType actionType) {
    m_Action = actionType;
}

void UserAction::setIdPlayer(int idPlayer) {
    m_IdPlayer = idPlayer;
}

void UserAction::setParam1(int8_t param1) {
    m_Param1 = param1;
}

void UserAction::setParam2(int8_t param2) {
    m_Param2 = param2;
}
