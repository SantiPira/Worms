#include "EventSender.h"

EventSender::EventSender(Protocol& protocol, int idPlayer, ProtectedQueue<std::string>& settingsQueue, bool isMyTurn)
    : m_Protocol(protocol), m_IsMyTurn(isMyTurn), m_KeepRunning(true), m_IdPlayer(idPlayer),
    m_SettingsQueue(settingsQueue), m_WeaponId(WeaponID::NO_WEAPON) {}

void EventSender::run() {
    while (isRunning()) {
        SDL_Event event;
        SDL_WaitEvent(&event);
        if (event.type == SDL_QUIT) {
            stop();
            return;
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
                m_StartAttackTime = std::chrono::system_clock::now();
            } else if (key == SDLK_h) {
                m_WeaponId = WeaponID::AXE;
                userAction = {ActionType::SET_WEAPON, m_IdPlayer, m_WeaponId};
            } else if (key == SDLK_j) {
                m_WeaponId = WeaponID::NO_WEAPON;
                userAction = {ActionType::UNSET_WEAPON, m_IdPlayer};
            } else if (key == SDLK_b) {
                m_WeaponId = WeaponID::BATE;
                userAction = {ActionType::SET_WEAPON, m_IdPlayer, m_WeaponId};
            } else if (key == SDLK_k){ //bazooka
                m_WeaponId = WeaponID::BAZOOKA;
                userAction = {ActionType::SET_WEAPON, m_IdPlayer, m_WeaponId};
            }else if(key == SDLK_g){ //greenbomb
                m_WeaponId = WeaponID::GREENBOMB;
                userAction = {ActionType::SET_WEAPON, m_IdPlayer, m_WeaponId};
            }else if (key == SDLK_DOWN) {
                if (m_WeaponId == WeaponID::BATE) {
                    userAction = {ActionType::DECREASE_ANGLE, m_IdPlayer};
                }
            } else if (key == SDLK_UP) {
                if (m_WeaponId == WeaponID::BATE) {
                    userAction = {ActionType::INCREASE_ANGLE, m_IdPlayer};
                }
            } else if (key == SDLK_1) { 
                std::cout << "toque algooooo\n";
                m_SettingsQueue.push("MUESTRO LISTA");
            } else if (key == SDLK_2) { 
                std::cout << "toque algooooo\n";
                m_SettingsQueue.push("GUARDO LISTA");  
            } else {
                std::cout << "key no mapeada: " << key << std::endl;
            }
        } else if (event.type == SDL_KEYUP && event.key.repeat == 0) {
            if (key == SDLK_d || key == SDLK_a) {
                userAction = {ActionType::STOP_MOVE, m_IdPlayer};
            } else if (key == SDLK_c) {
                userAction = attack();
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

UserAction EventSender::attack() {
    std::chrono::duration<double> elapsedSeconds{};
    switch (m_WeaponId) {
        case WeaponID::BATE:
            elapsedSeconds = std::chrono::system_clock::now() - m_StartAttackTime;
            uint8_t force;
            if (elapsedSeconds.count() >= BatePotency::LOW_POTENCY
                && elapsedSeconds.count() < BatePotency::MEDIUM_POTENCY) {
                std::cout << "LOW" << std::endl;
                force = BateForce::LOW;
            } else if (elapsedSeconds.count() > BatePotency::MEDIUM_POTENCY
                && elapsedSeconds.count() < BatePotency::HIGH_POTENCY) {
                std::cout << "MEDIUM" << std::endl;
                force = BateForce::MEDIUM;
            } else {
                std::cout << "HIGH" << std::endl;
                force = BateForce::HIGH;
            }
            return {ActionType::ATTACK, m_IdPlayer, force};
        case WeaponID::AXE:
            return {ActionType::ATTACK, m_IdPlayer};
        case WeaponID::NO_WEAPON:
            return {};
        default:
            return {};
    }
}
