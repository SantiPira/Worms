#include "EventSender.h"

EventSender::EventSender(Protocol& protocol, int idPlayer, ProtectedQueue<std::string>& settingsQueue, bool isMyTurn)
    : m_Protocol(protocol), m_IsMyTurn(isMyTurn), m_KeepRunning(true), m_IdPlayer(idPlayer),
    m_SettingsQueue(settingsQueue), m_WeaponId(WeaponID::NO_WEAPON), m_ToolId(NO_TOOL) {}

void EventSender::run() {
    while (isRunning()) {
        SDL_Event event;
        #ifdef TEST
            SDL_Keycode key;
            event.type = SDL_KEYDOWN;
            event.key.repeat = 0;
            if (std::cin.peek() != EOF) {
                char input;
                std::cin >> input;

                switch (input) {
                    case 'a':
                        key = SDLK_a;
                        break;
                    case 'd':
                        key = SDLK_d;
                        break;
                    case '1':
                        key = SDLK_1;
                        break;
                    case '2':
                        key = SDLK_2;
                        break;
                    case 'e':
                        key = SDLK_SPACE;
                        break;
                    case 'c':
                        key = SDLK_c;
                        break;
                    case 'h':
                        key = SDLK_h;
                        break;
                    case 'k':
                        key = SDLK_k;
                        break;
                    case 'j':
                        key = SDLK_j;
                        break;
                    case 'b':
                        key = SDLK_b;
                        break;
                    case 'o':
                        key = SDLK_DOWN;
                        break;
                    case 'p':
                        key = SDLK_UP;
                        break;
                    case 'm':
                        key = SDLK_m;
                        break;
                    case 'q':
                        key = SDLK_m;
                        event.type = SDL_QUIT;
                        break;
                    case 's':
                        key = SDLK_a;
                        event.type = SDL_KEYUP;
                        break;
                    case 'w':
                        key = SDLK_d;
                        event.type = SDL_KEYUP;
                        break;
                    case 'v':
                        key = SDLK_c;
                        event.type = SDL_KEYUP;
                        break;
                    case '.':
                        key = SDLK_m;
                        event.type = SDL_MOUSEBUTTONDOWN;
                        event.button.x = 0;
                        event.button.y = 0;
                        break;
                    default:
                        key = SDLK_UNKNOWN;
                        break;
                }
            }   
        #else
            SDL_WaitEvent(&event);
            SDL_Keycode key = event.key.keysym.sym;
        #endif

        if (event.type == SDL_QUIT) {
            stop();
            break;
        }

        UserAction userAction;
        if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
            if (key == SDLK_d) {
                userAction = {ActionType::MOVE, m_IdPlayer, Direction::RIGHT};
            } else if (key == SDLK_1) {
                m_SettingsQueue.push("MUESTRO LISTA");
            } else if (key == SDLK_2) {
                m_SettingsQueue.push("GUARDO LISTA");
            } else if (key == SDLK_g) {
                m_WeaponId = WeaponID::GRANADE;
                userAction = {ActionType::SET_WEAPON, m_IdPlayer, m_WeaponId};
            } else if (key == SDLK_a) {
                userAction = {ActionType::MOVE, m_IdPlayer, Direction::LEFT};
            } else if (key == SDLK_SPACE) {
                userAction = {ActionType::JUMP, m_IdPlayer};
            } else if (key == SDLK_c) {
                std::cout << "ATACO\n";
                m_StartAttackTime = std::chrono::system_clock::now();
            } else if (key == SDLK_h) {
                m_WeaponId = WeaponID::AXE;
                userAction = {ActionType::SET_WEAPON, m_IdPlayer, m_WeaponId};
            } else if (key == SDLK_k) {
                m_WeaponId = WeaponID::BAZOOKA;
                userAction = {ActionType::SET_WEAPON, m_IdPlayer, m_WeaponId};
            } else if (key == SDLK_j) {
                m_WeaponId = WeaponID::NO_WEAPON;
                userAction = {ActionType::UNSET_WEAPON, m_IdPlayer};
            } else if (key == SDLK_b) {
                m_WeaponId = WeaponID::BATE;
                userAction = {ActionType::SET_WEAPON, m_IdPlayer, m_WeaponId};
            } else if (key == SDLK_DOWN) {
                if (m_WeaponId == WeaponID::BATE || m_WeaponId == WeaponID::BAZOOKA) {
                    userAction = {ActionType::DECREASE_ANGLE, m_IdPlayer};
                }
            } else if (key == SDLK_UP) {
                if (m_WeaponId == WeaponID::BATE || m_WeaponId == WeaponID::BAZOOKA) {
                    userAction = {ActionType::INCREASE_ANGLE, m_IdPlayer};
                }
            } else if (key == SDLK_m) {
                userAction = {ActionType::SELF_KILL, m_IdPlayer};
            } else if (key == SDLK_t) {
                userAction = {ActionType::SET_TOOL, m_IdPlayer};
                m_ToolId = ToolID::TELEPORTER;
            } else {
                std::cout << "key no mapeada: " << key << std::endl;
            }
        } else if (event.type == SDL_KEYUP && event.key.repeat == 0) {
            if (key == SDLK_d || key == SDLK_a) {
                userAction = {ActionType::STOP_MOVE, m_IdPlayer};
            } else if (key == SDLK_c) {
                std::cout << "ENVIO ATAQUE\n";
                userAction = attack();
            } else {
                std::cout << "key no mapeada: " << key << std::endl;
            }
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            if (m_ToolId == TELEPORTER) {
                float posX = WorldScale::pixelToWorldX(event.button.x, 0);
                float posY = WorldScale::pixelToWorldY(event.button.y, 0);
                userAction = {ActionType::USE_TOOL, m_IdPlayer, posX, posY};
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
    //!m_Protocol.isClosed() && 
    return m_KeepRunning.load();
}

void EventSender::stop() {
    m_KeepRunning.store(false);
    if(!m_Protocol.isClosed()) {
        m_Protocol.shutdown(SHUT_RDWR);
        m_Protocol.close();
    }
}

void EventSender::setIsRunning(bool isRunning) {
    m_KeepRunning.store(isRunning);
}

void EventSender::setItsMyTurn(bool isMyTurn) {
    if (isMyTurn) {
        std::cout << "MI TURNO ID: " << m_IdPlayer << std::endl;
    } else {
        std::cout << "NO ES MI TURNO ID: " << m_IdPlayer << std::endl;
    }
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
        case WeaponID::BAZOOKA:
            std::cout << "KABOOM\n";
            return {ActionType::ATTACK, m_IdPlayer};
        case WeaponID::NO_WEAPON:
            return {};
        default:
            return {};
    }
}


