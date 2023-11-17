#include "ClientManager.h"
#include "EventSender.h"
#include "client_receiver.h"
#include "GameClient.h"

ClientManager::ClientManager(Protocol *protocol, int idPlayer, int cantPlayers) : m_Protocol(protocol),
    m_IdPlayer(idPlayer), m_CantPlayers(cantPlayers), settingsQueue(100), gameUpdates(100), m_KeepRunning(true) {}

void ClientManager::init() {
    try {
        const std::vector<Grd> &map = m_Protocol->recvMap();

        std::vector<GameUpdate> initInfo;
        for (int i = 0; i < m_CantPlayers; i++) {
            initInfo.push_back(m_Protocol->recvGameUpdate());
        }

        EventSender eventSender(*m_Protocol, m_IdPlayer, std::ref(settingsQueue));
        ClientReceiver receiver(*m_Protocol, std::ref(gameUpdates));

        m_Game = GameClient();
        m_Game.Init(map, m_IdPlayer, std::ref(initInfo));
        eventSender.start();
        receiver.start();
        gameLoop();
        receiver.join();
        eventSender.join();

    } catch (std::exception &exception) {
        fprintf(stderr, "%s", exception.what());
        SDL_Quit();
        //TODO: throw Exception para que el main la catchee y devuelva codigo de error 1
        return;
    }
}

void ClientManager::gameLoop() {
    auto lastTime = std::chrono::system_clock::now();
    while (m_KeepRunning) {
        GameUpdate svUpdate{};

        auto current = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsedSeconds = current - lastTime;

        gameUpdates.try_pop(svUpdate);

        m_Game.Update(elapsedSeconds.count(), svUpdate); // me setea en memoria el sprite que voy a renderizar
        WormDie wormDie{};
        /*if (svUpdate.m_SelfCondition == GameAction::WORM_DIE) {
            wormDie.idPlayer = svUpdate.player_id;
            wormDie.isDie = true;
            if (svUpdate.player_id == m_IdPlayer) {
                m_KeepRunning = false;
            }
        }*/
        m_Game.Render(wormDie);


        lastTime = current;
    }

    m_Game.Release();
}




