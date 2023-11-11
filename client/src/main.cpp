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
            const std::vector<Grd> &map = protocol->recvMap();
            GameUpdate gameUpdate = protocol->recvGameUpdate();
            ProtectedQueue<std::string> settingsQueue(100);
            ProtectedQueue<GameUpdate> gameUpdates(100);
            gameUpdates.push(gameUpdate);
            EventSender eventSender(*protocol, gameUpdate.player_id, std::ref(settingsQueue));
            ClientReceiver receiver(*protocol, std::ref(gameUpdates));
            auto game = GameClient();
            game.Init(map);
            auto lastTime = std::chrono::system_clock::now();
            eventSender.start();
            receiver.start();
            while (game.IsRunning()) {
                std::vector<GameUpdate> serverUpdates;
                auto current = std::chrono::system_clock::now();
                std::chrono::duration<double> elapsedSeconds = current - lastTime;
                gameUpdates.try_pop(serverUpdates, 10);
                //game.HandleEvents();

                for (auto &serverUpdate : serverUpdates) {
                    game.Update(elapsedSeconds.count(), serverUpdate);
                    game.Render();
                }
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
