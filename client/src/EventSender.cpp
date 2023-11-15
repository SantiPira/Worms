#include "EventSender.h"

EventSender::EventSender(Protocol& protocol, int idPlayer, ProtectedQueue<std::string>& settingsQueue)
    : m_Protocol(protocol), itsMyTurn(false), m_KeepRunning(true), m_IdPlayer(idPlayer),
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
        if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
            if (key == SDLK_d) {
                std::cout << "enviando accion de moverse a la derecha" << std::endl;
                UserAction userAction(ActionType::MOVE, m_IdPlayer, Direction::RIGHT);
                m_Protocol.sendUserAction(userAction);
            } else if (key == SDLK_a) {
                std::cout << "enviando accion de moverse a la izquierda" << std::endl;
                UserAction userAction(ActionType::MOVE, m_IdPlayer, Direction::LEFT);
                m_Protocol.sendUserAction(userAction);
            } else if (key == SDLK_SPACE) {
                std::cout << "enviando accion de saltar" << std::endl;
                UserAction userAction(ActionType::JUMP, m_IdPlayer);
                m_Protocol.sendUserAction(userAction);
            } else if (key == SDLK_c) {
                std::cout << "enviando accion de atacar" << std::endl;
                UserAction userAction(ActionType::ATTACK, m_IdPlayer);
                m_Protocol.sendUserAction(userAction);
            } else if (key == SDLK_h) {
                std::cout << "Sacando Hacha" << std::endl;
                UserAction userAction(ActionType::SET_WEAPON, m_IdPlayer, Weapon::AXE); // TIPO DE ARMA
                m_Protocol.sendUserAction(userAction);
            } else if (key == SDLK_j) {
                std::cout << "Guardando Hacha" << std::endl;
                UserAction userAction(ActionType::UNSET_WEAPON, m_IdPlayer); // TIPO DE ARMA
                m_Protocol.sendUserAction(userAction);
            } else {
                std::cout << "key no mapeada: " << key << std::endl;
            }
        } else if (event.type == SDL_KEYUP && event.key.repeat == 0) {
            if (key == SDLK_d || key == SDLK_a) {
                std::cout << "enviando accion de dejar de moverse" << std::endl;
                UserAction userAction(ActionType::STOP_MOVE, m_IdPlayer);
                m_Protocol.sendUserAction(userAction);
            } else {
                std::cout << "key no mapeada: " << key << std::endl;
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
