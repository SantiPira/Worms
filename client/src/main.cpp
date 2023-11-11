#include <iostream>
#include <QApplication>
#include <SDL.h>
#include "mainWindow.h"
#include "GameClient.h"

int main(int argc, char *argv[]) {
    try{
        QApplication app(argc, argv);
        MainWindow window_connect;
        window_connect.show();
        return app.exec();
        //try {
            //auto lastTime = std::chrono::system_clock::now();
            //Protocol* protocol = window_connect.getProtocol();
            //const std::vector<Grd> &map = protocol->recvMap();
            //GameUpdate gameUpdate = protocol->recvGameUpdate();
            //ProtectedQueue<std::string> settingsQueue(100);
            //ProtectedQueue<GameUpdate> gameUpdates(100);
            //gameUpdates.push(gameUpdate);

            /*
            EventSender eventSender(*protocol, 1, std::ref(settingsQueue));
            ClientReceiver receiver(*protocol, std::ref(gameUpdates));
            auto game = GameClient();
            game.Init(map);
            eventSender.start();
            receiver.start();
            while (game.IsRunning()) {
                auto current = std::chrono::system_clock::now();
                std::chrono::duration<double> elapsedSeconds = current - lastTime;

                //game.HandleEvents();

                game.Update(elapsedSeconds.count());

                game.Render();
            }

            game.Release();
            receiver.join();
            eventSender.join();
            */
        //} catch (std::exception &exception) {
        //    fprintf(stderr, "%s", exception.what());
        //    SDL_Quit();
       //     return -1;
        //}
    }catch(std::exception &e){
        std::cerr << e.what() << std::endl;
        return 1;
    }catch(...){
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }
    //return 0;
}
