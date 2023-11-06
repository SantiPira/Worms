#include "../include/Client.h"


Client::Client(Socket peer, MatchesMonitor* matches) : m_Protocol(std::move(peer)), m_KeepRunning(true),
    m_Matches(matches), m_UpdatesGame(100) {}

void Client::run() {
    while (!m_Protocol.isClosed() && !hasGame) {
        GameInfo clientResponse = m_Protocol.recvGameInfo();
        switch (clientResponse.getIdAction()) {
            case InitGameEnum::CREATE_GAME: {
                idGame = m_Matches->createGame(clientResponse.getGameProperties()[0].m_GameName,
                                               clientResponse.getGameProperties()[0].m_MapName);
                idPlayer = m_Matches->addPlayer(idGame, &m_UpdatesGame);
                m_InputActions = m_Matches->getInputActionGame(idGame);
                hasGame = true;
                break;
            }
            case InitGameEnum::JOIN_GAME: {
                idGame = clientResponse.getGameProperties()[0].m_idGame;
                idPlayer = m_Matches->addPlayer(idGame, &m_UpdatesGame);
                m_InputActions = m_Matches->getInputActionGame(idGame);
                hasGame = true;
                break;
            }
            case InitGameEnum::LIST_GAMES: {
                GameInfo gameInfo(InitGameEnum::LIST_GAMES, m_Matches->getGameProperties());
                m_Protocol.sendGameInfo(std::ref(gameInfo));
            }
            default: {
                break;
            }
        }
    }
    sendMap();
    ClientSender sender(std::ref(m_Protocol), &m_UpdatesGame, idPlayer);
    sender.start();
    //Receiver state
    while (!m_Protocol.isClosed()) {
        //handlerInitGame->handle(std::ref(clientInitGame));
        //clientInitGame.executeAction(std::ref(m_Matches), std::ref(m_UpdatesGame), idPlayer, idGame);
        m_InputActions->push("clientResponse");
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

void Client::sendMap() {
    std::vector<Grd> map = ParseMapFromFile::parse(m_Matches->getMapName(idGame));
    m_Protocol.sendMap(std::ref(map));
}

