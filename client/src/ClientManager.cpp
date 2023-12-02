#include <QMessageBox>
#include <QPushButton>
#include "ClientManager.h"
#include "client_receiver.h"
#include "GameClient.h"

ClientManager::ClientManager(Protocol *protocol, int idPlayer, int cantPlayers, WaitingWindow* waitingWindow) : m_Protocol(protocol),
    m_IdPlayer(idPlayer), m_CantPlayers(cantPlayers), settingsQueue(100), gameUpdates(100), m_KeepRunning(true),
    m_WaitingWindow(waitingWindow), m_EndGame(false), m_YouWin(false) {}

void ClientManager::init() {
    try {
        const std::vector<Grd> &map = m_Protocol->recvMap();
        GameUpdate turnInfo = m_Protocol->recvGameUpdate();
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
    while (!m_EndGame) {
        GameUpdate svUpdate{};
        m_Game.projectile_launched = false;

        auto current = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsedSeconds = current - lastTime;

        std::string user_action = "a";
        settingsQueue.try_pop(user_action);

        if (user_action == "MUESTRO LISTA") {
            m_Game.se_muestra_la_lista_de_armas = true;
        } else if (user_action == "GUARDO LISTA") {
            m_Game.se_muestra_la_lista_de_armas = false;
        }

        gameUpdates.try_pop(svUpdate);

        if(svUpdate.m_Movement == GameAction::PROJECTILE_LAUNCHED) {
            std::cout << "LANZE UN PROYECTIL!!!!!!\n";
            std::cout << "POS X: " << WorldScale::worldToPixelX(svUpdate.x_pos, svUpdate.width) << std::endl;
            std::cout << "POS Y: " <<  WorldScale::worldToPixelY(svUpdate.y_pos, svUpdate.height) << std::endl;
            m_Game.projectile_launched = true;
        }

        if (svUpdate.m_TurnInfo == START_TURN) {
            m_Game.resetTurn(svUpdate.player_id, svUpdate.m_PlayerName, svUpdate.m_SecondsPerTurn);
        } else {
            if (svUpdate.m_TurnInfo == END_GAME) {
                m_Winner = svUpdate.m_PlayerName;
                m_YouWin = svUpdate.player_id == m_IdPlayer;
                m_EndGame = true;
            }
            m_Game.Update(elapsedSeconds.count(), svUpdate);
        }
        m_Game.Render();

        lastTime = current;
        SDL_Delay(12);

        if (m_EndGame) {
            eventSender.setIsRunning(false);
            endGameWindow();
            break;
        }
    }
}

void ClientManager::endGameWindow() {
    std::string winner;
    std::string finalImagePath;
    if (m_YouWin) {
        winner = "Ganaste!";
        finalImagePath = std::filesystem::current_path().concat("/resources/Fondos/worms-start.png");
    } else {
        winner = "El ganador es: " + m_Winner + ".";
        finalImagePath = std::filesystem::current_path().concat("/resources/Fondos/worms-start.png");
    }
    QDialog dialog;
    dialog.setWindowTitle("Worms");

    QLabel *label = new QLabel(winner.c_str());
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 20px; color: black; font-weight: bold;");

    QPushButton *button = new QPushButton("Salir");
    button->setFixedSize(100, 50);
    QObject::connect(button, &QPushButton::clicked, [&]() {
        m_Game.Release();
        dialog.close();
    });

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(button);
    buttonLayout->addStretch(1);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addLayout(buttonLayout);

    dialog.setLayout(layout);
    dialog.setFixedSize(500, 300);

    dialog.setStyleSheet("QDialog {background-image: url(" + QString(finalImagePath.c_str()) + ")}");
    dialog.exec();
}




