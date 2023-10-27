#include "../include/Client.h"
#include "../../common_libs/include/messages/server/to_client/InfoServer.h"
#include "../../common_libs/include/messages/server/from_client/ClientResponse.h"
#include <iostream>

Client::Client(Socket peer, MatchesMonitor* matches) : m_Protocol(std::move(peer)), m_KeepRunning(true),
    m_Matches(matches), m_UpdatesGame(100) {}

void Client::run() {
    InfoServer infoServer(ActionToClient::TC_GAME_LIST, m_Matches->getGames(), m_Matches->getAllPlayers());
    m_Protocol.sendMessage(std::ref(infoServer));
    ClientResponse clientResponse;
    while (!m_Protocol.isClosed() && !clientResponse.isQuit()) {
        m_Protocol.recvClientResponse(clientResponse);
        switch (clientResponse.getAction()) {
            case ActionFromClient::FC_CREATE_GAME: {
                idGame = m_Matches->createGame(&m_UpdatesGame);
                hasGame = true;
                break;
            }
            case ActionFromClient::FC_JOIN_GAME: {
                m_Protocol.recvClientResponse(clientResponse);
                m_Matches->addPlayer(idGame, &m_UpdatesGame);
                hasGame = true;
                break;
            }
            case ActionFromClient::FC_LIST_GAMES: {
                infoServer.setIdAction(ActionToClient::TC_GAME_LIST);
                infoServer.setGames(m_Matches->getGames());
                infoServer.setPlayers(m_Matches->getAllPlayers());
                m_Protocol.sendMessage(std::ref(infoServer));
            }
            default: {
                break;
            }
        }
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
