#include "../include/Client.h"
#include "../../common_libs/include/InfoServer.h"
#include "../../common_libs/include/ClientRequest.h"
#include <iostream>

Client::Client(Socket peer, Games* games) : m_Protocol(std::move(peer)), m_KeepRunning(true), m_Games(games) {}

void Client::run() {
    std::cout << "Client running" << std::endl;
    InfoServer infoServer(0x00, m_Games->getGames(), m_Games->getAllPlayers());
    m_Protocol.sendMessage(std::ref(infoServer));
    ClientRequest clientRequest;
    m_Protocol.recvClientRequest(clientRequest);
    while (m_KeepRunning && !clientRequest.isQuit()) {
        switch (clientRequest.getAction()) {
            case 0x01: {
                idGame = m_Games->createGame();
                hasGame = true;
                break;
            }
            case 0x02: {
                m_Protocol.recvClientRequest(clientRequest);
                m_Games->addPlayer(idGame);
                hasGame = true;
                break;
            }
            case 0x03: {
                //gamesAvailables.setGames(m_Games->getAllPlayers());
                //gamesAvailables.setGamesAvailables(m_Games->getGames());
                m_Protocol.sendMessage(std::ref(infoServer));
            }
            default: {
                break;
            }
        }
        m_Protocol.recvClientRequest(clientRequest);
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
