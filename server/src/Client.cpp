#include "../include/Client.h"

#define ID_PLAYER_INVALID (-1)

Client::Client(Socket peer, MatchesMonitor* matches) : m_Protocol(std::move(peer)), m_KeepRunning(true),
    m_Matches(matches), m_UpdatesGame(100), m_Sender(std::ref(m_Protocol), &m_UpdatesGame, ID_PLAYER_INVALID) {}

void Client::run() {
    try {
        while (isRunning() && !hasGame) {
            lobbyGame();
        }
        if (hasGame) {
            initGame();
        }

    } catch (const LibError& e) {
        std::cerr << "LibError exception e.what(): " << e.what() << std::endl;
    } catch (const std::exception &e1) {
        std::cerr << "Unexpected error e.what(): " << e1.what() << std::endl;
    }
    destroyClient();
}

void Client::initGame() {
    sendMap();
    m_Sender.setPlayerId(m_IdPlayer);
    m_Sender.start();
    //Receiver state
    while (isRunning()) {
        try{
            m_InputActions->push(m_Protocol.recvUserAction());
        } catch (...) {
            //should do nothing, either protocol has closed or queue is closed 
        }
    }
    m_Sender.stop();
    m_Sender.join();
}

void Client::lobbyGame() {
    GameInfo clientResponse = m_Protocol.recvGameInfo();
    if (!m_Protocol.isClosed()) {
        switch (clientResponse.getIdAction()) {
            case CREATE_GAME: {
                m_IdGame = m_Matches->createGame(clientResponse.getGameProperties()[0].m_GameName,
                                                 clientResponse.getGameProperties()[0].m_MapName,
                                                 clientResponse.getGameProperties()[0].m_Players);
                m_IdPlayer = m_Matches->addPlayer(m_IdGame, &m_UpdatesGame);
                GameInfo response(InitGameEnum::ID_PLAYER, m_IdPlayer);
                m_Protocol.sendGameInfo(response);
                m_InputActions = m_Matches->getInputActionGame(m_IdGame);
                hasGame = true;
                break;
            }
            case JOIN_GAME: {
                m_IdGame = clientResponse.getGameProperties()[0].m_idGame;
                m_IdPlayer = m_Matches->addPlayer(m_IdGame, &m_UpdatesGame);
                GameInfo response(InitGameEnum::ID_PLAYER, m_IdPlayer);
                m_Protocol.sendGameInfo(response);
                m_InputActions = m_Matches->getInputActionGame(m_IdGame);
                hasGame = true;
                break;
            }
            case LIST_GAMES: {
                GameInfo gameInfo(LIST_GAMES, m_Matches->getGameProperties());
                m_Protocol.sendGameInfo(std::ref(gameInfo));
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
    m_KeepRunning.store(false);
    m_Protocol.shutdown(SHUT_RDWR);
    m_Protocol.close();
}

void Client::sendMap() {
    std::vector<Grd> map = ParseMapFromFile::parse(m_Matches->getMapName(m_IdGame));
    for (auto& grd : map) {
        GrdEnum grdEnum = grd.grdType;
        if (grdEnum == GRD_LARGE_HORIZONTAL) {
            grd.width = GrdWidthEnum::GRD_HORIZONTAL_WIDTH_LARGE;
            grd.height = GrdHeightEnum::GRD_HORIZONTAL_HEIGHT_LARGE;
        }
    }
    m_Protocol.sendMap(std::ref(map));
}

void Client::destroyClient() {
    if (hasGame) {
        m_Matches->removePlayer(m_IdGame, m_IdPlayer);
    }
    if (m_KeepRunning.load()) {
        kill();
    }
}

int Client::getIdPlayer() const {
    return m_IdPlayer;
}

int Client::getIdGame() const {
    return m_IdGame;
}

bool Client::isRunning() {
    return m_KeepRunning.load() && !m_Protocol.isClosed();
}

