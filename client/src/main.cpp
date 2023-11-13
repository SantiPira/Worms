#include <iostream>
#include <QApplication>
#include <SDL.h>
#include "mainWindow.h"
#include "GameClient.h"
#include "messages/server/GameUpdate.h"

int main(int argc, char *argv[]) {
    try{
        QApplication app(argc, argv);
        MainWindow window_connect;
        window_connect.show();
        app.exec();
        try {
            Protocol* protocol = window_connect.getProtocol();
            int players = window_connect.getCantPlayers();
            const std::vector<Grd> &map = protocol->recvMap();
            //GameUpdate gameUpdate = protocol->recvGameUpdate();
            ProtectedQueue<std::string> settingsQueue(100);
            ProtectedQueue<GameUpdate> gameUpdates(100);
            std::vector<GameUpdate> initInfo;
            for (int i = 0; i < players; i++) {
                initInfo.push_back(protocol->recvGameUpdate());
            }
            int idPlayer = window_connect.getIdPlayer();
            std::cout << "El id del jugador es: " << idPlayer << std::endl;
            EventSender eventSender(*protocol, idPlayer, std::ref(settingsQueue));
            ClientReceiver receiver(*protocol, std::ref(gameUpdates));
            auto game = GameClient();
            game.Init(map, idPlayer, std::ref(initInfo));
            eventSender.start();
            receiver.start();

            auto lastTime = std::chrono::system_clock::now();
            while (game.IsRunning()) {
                GameUpdate svUpdate{};
                auto current = std::chrono::system_clock::now();
                std::chrono::duration<double> elapsedSeconds = current - lastTime;

                gameUpdates.try_pop(svUpdate);

                game.Update(elapsedSeconds.count(), svUpdate);
                game.Render();

                lastTime = current;
            }
            game.Release();
            receiver.join();
            eventSender.join();
        } catch (std::exception &exception) {
            fprintf(stderr, "%s", exception.what());
            SDL_Quit();
            return -1;
        }
    }catch(std::exception &e){
        std::cerr << e.what() << std::endl;
        return 1;
    }catch(...){
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }
    return 0;
}
