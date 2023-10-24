#include "../include/Client.h"
#include <iostream>

Client::Client(Socket peer, Games* games) : m_Protocol(std::move(peer)), m_KeepRunning(true), m_Games(games) {}

void Client::run() {
    MessageCoreGamesAvailables gamesAvailables(ActionSVToCLEnum::SV_CORE_MESSAGE, m_Games->getGames(),
                                                 m_Games->getAllPlayers());
    m_Protocol.sendMessage(std::ref(gamesAvailables));
    PlayerInfoMessage message;
    m_Protocol.receiveMessage(std::ref(message));
    ActionFromClientEnum action = message.getAction();
    while (m_KeepRunning) {
        switch (action) {
            case ActionFromClientEnum::CL_CREATE_GAME: {
                idGame = m_Games->createGame();
                hasGame = true;
                break;
            }
            case ActionFromClientEnum::CL_JOIN_GAME: {
                m_Protocol.receiveMessage(std::ref(message));
                m_Games->addPlayer(idGame);
                hasGame = true;
                break;
            }
            case ActionFromClientEnum::CL_LIST_GAMES: {
                gamesAvailables.setGames(m_Games->getAllPlayers());
                gamesAvailables.setGamesAvailables(m_Games->getGames());
                m_Protocol.sendMessage(std::ref(gamesAvailables));
            }
            default: {
                break;
            }
        }
        m_Protocol.receiveMessage(std::ref(message));
    }
}


bool Client::isDead() {
    return !m_KeepRunning.load();
}

void Client::stop() {
    m_KeepRunning.store(false);
}

void Client::kill() {
    m_Protocol.shutdown(SHUT_RDWR);
    m_Protocol.close();
}

