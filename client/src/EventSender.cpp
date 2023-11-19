#include "EventSender.h"

EventSender::EventSender(Protocol& protocol, int idPlayer, ProtectedQueue<std::string>& settingsQueue, bool isMyTurn)
    : m_Protocol(protocol), m_IsMyTurn(isMyTurn), m_KeepRunning(true), m_IdPlayer(idPlayer),
    m_SettingsQueue(settingsQueue) {}

void EventSender::run() {
    while (isRunning()) {
        SDL_Event event;
        SDL_WaitEvent(&event);
        if (event.type == SDL_QUIT) {
            stop();
            break;
        }
        SDL_Keycode key = event.key.keysym.sym;
        UserAction userAction;
        if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
            if (key == SDLK_d) {
                userAction = {ActionType::MOVE, m_IdPlayer, Direction::RIGHT};
            } else if (key == SDLK_a) {
                userAction = {ActionType::MOVE, m_IdPlayer, Direction::LEFT};
            } else if (key == SDLK_SPACE) {
                std::cout << "ID: " << m_IdPlayer << " JUMP" << std::endl;
                userAction = {ActionType::JUMP, m_IdPlayer};
            } else if (key == SDLK_c) {
                userAction = {ActionType::ATTACK, m_IdPlayer};
            } else if (key == SDLK_h) {
                userAction = {ActionType::SET_WEAPON, m_IdPlayer, WeaponID::AXE};
            } else if (key == SDLK_j) {
                userAction = {ActionType::UNSET_WEAPON, m_IdPlayer};
            } else {
                std::cout << "key no mapeada: " << key << std::endl;
            }
        } else if (event.type == SDL_KEYUP && event.key.repeat == 0) {
            if (key == SDLK_d || key == SDLK_a) {
                userAction = {ActionType::STOP_MOVE, m_IdPlayer};
            } else {
                std::cout << "key no mapeada: " << key << std::endl;
            }
        }

        if (userAction.getAction() != ActionType::NONE) {
            bool isMyTurn = m_IsMyTurn.load();
            if (isMyTurn) {
                std::cout << "ID: " << m_IdPlayer << " Enviando accion: " << userAction.getAction() << std::endl;
                m_Protocol.sendUserAction(userAction);
            }
        }
    }
}

bool EventSender::isRunning() {
    return !m_Protocol.isClosed() && m_KeepRunning.load();
}

void EventSender::stop() {
    m_KeepRunning.store(false);
    m_Protocol.shutdown(SHUT_RDWR);
    m_Protocol.close();
}

void EventSender::setItsMyTurn(bool isMyTurn) {
    std::cout << "ID: " << m_IdPlayer << " Cambio de turno: " << isMyTurn << std::endl;
    this->m_IsMyTurn.store(isMyTurn);
}
