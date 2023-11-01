#include "../include/Client.h"

Client::Client(Socket peer, MatchesMonitor* matches) : m_Protocol(std::move(peer)), m_KeepRunning(true),
    m_Matches(matches), m_UpdatesGame(100) {}

void Client::run() {
    InfoServer infoServer(ActionToClient::TC_GAME_LIST, m_Matches->getGames(), m_Matches->getAllPlayers());
    m_Protocol.sendMessage(std::ref(infoServer));
    while (!m_Protocol.isClosed()) {
    }
    ClientSender sender(std::ref(m_Protocol), &m_UpdatesGame, idPlayer);
    sender.start();
    //Receiver state
    while (!m_Protocol.isClosed()) {
        ClientInitGame clientInitGame;
        std::unique_ptr<HandlerInitGame> handler = factoryHandler(clientInitGame.getAction(), clientInitGame);
        //handlerInitGame->handle(std::ref(clientInitGame));
        m_Protocol.recvClientInitGame(std::ref(clientInitGame));
        //clientInitGame.executeAction(std::ref(m_Matches), std::ref(m_UpdatesGame), idPlayer, idGame);
        m_InputActions->push("clientResponse");
    }
}
/*switch (clientResponse.getAction()) {
            case ActionFromClient::FC_CREATE_GAME: {
                idGame = m_Matches->createGame();
                idPlayer = m_Matches->addPlayer(idGame, &m_UpdatesGame);
                m_InputActions = m_Matches->getInputActionGame(idGame);
                hasGame = true;
                break;
            }
            case ActionFromClient::FC_JOIN_GAME: {
                idGame = clientResponse.getIdGame();
                idPlayer = m_Matches->addPlayer(idGame, &m_UpdatesGame);
                m_InputActions = m_Matches->getInputActionGame(idGame);
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
        }*/

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

std::unique_ptr<HandlerInitGame> Client::factoryHandler(ActionFromClient actionFromClient, ClientInitGame& clientInitGame) {
    if (actionFromClient == ActionFromClient::FC_CREATE_GAME) {
        return std::make_unique<CreateGameHandler>(std::ref(clientInitGame));
    }
}
