#include "ClientManager.h"
#include "client_receiver.h"
#include "GameClient.h"

ClientManager::ClientManager(Protocol *protocol, int idPlayer, int cantPlayers, WaitingWindow* waitingWindow) : m_Protocol(protocol),
    m_IdPlayer(idPlayer), m_CantPlayers(cantPlayers), settingsQueue(100), gameUpdates(100), m_KeepRunning(true),
    m_WaitingWindow(waitingWindow) {}

void ClientManager::init() {
    try {
        std::cout << "Client ID: " << m_IdPlayer << std::endl;
        const std::vector<Grd> &map = m_Protocol->recvMap();
        GameUpdate turnInfo = m_Protocol->recvGameUpdate();
        std::cout << "Seconds: " << turnInfo.m_SecondsPerTurn << std::endl;
        std::vector<GameUpdate> initInfo;
        
        for (int i = 0; i < m_CantPlayers; i++) {
            initInfo.push_back(m_Protocol->recvGameUpdate());
        }

        //Aca deberia cerrarse la ventana de espera pero eso no pasa.
        //m_WaitingWindow->close();

        EventSender eventSender(*m_Protocol, m_IdPlayer, std::ref(settingsQueue), turnInfo.player_id == m_IdPlayer);
        ClientReceiver receiver(*m_Protocol, std::ref(gameUpdates), std::ref(eventSender), m_IdPlayer);

        m_Game = GameClient();
        m_Game.Init(map, m_IdPlayer, std::ref(initInfo), std::ref(turnInfo));
        eventSender.start();
        receiver.start();
        gameLoop(eventSender);
        receiver.join();
        eventSender.join();

    } catch (std::exception &exception) {
        fprintf(stderr, "%s", exception.what());
        SDL_Quit();
        //TODO: throw Exception para que el main la catchee y devuelva codigo de error 1
        return;
    }
}

void ClientManager::gameLoop(EventSender& eventSender) {
    auto lastTime = std::chrono::system_clock::now();
    while (eventSender.isRunning()) {
        GameUpdate svUpdate{};

        auto current = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsedSeconds = current - lastTime;

        std::string user_action = "a";
        settingsQueue.try_pop(user_action);

        if (user_action == "MUESTRO LISTA") {
            m_Game.se_muestra_la_lista_de_armas = true;
        } else if (user_action == "GUARDO LISTA") {
            m_Game.se_muestra_la_lista_de_armas = false;
        }

        if(svUpdate.m_Movement == GameAction::PROJECTILE_LAUNCHED) {
            std::cout << "LANZE UN PROYECTIL!!!!!!\n";
        }
        gameUpdates.try_pop(svUpdate);

        if (svUpdate.m_TurnInfo != INVALID_ACTION) {
            m_Game.resetTurn(svUpdate.player_id, svUpdate.m_PlayerName, svUpdate.m_SecondsPerTurn);
        } else {
            m_Game.Update(elapsedSeconds.count(), svUpdate);
        }
        m_Game.Render();

        lastTime = current;
        SDL_Delay(12);
    }
    m_Game.Release();
}




