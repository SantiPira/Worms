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
        app.exec();
        Protocol* protocol = window_connect.getProtocol();
        ProtectedQueue<std::string> settingsQueue(100);
        ProtectedQueue<std::string> gameUpdates(100);
        EventSender eventSender(*protocol, 1, std::ref(settingsQueue));
        ClientReceiver receiver(*protocol, std::ref(gameUpdates));
        eventSender.start();
        receiver.start();
        try {
            auto game = GameClient();
            game.Init();

            while (game.IsRunning()) {
                game.HandleEvents();

                game.Update();

                game.Render();
            }

            game.Release();
        } catch (std::exception &exception) {
            fprintf(stderr, "%s", exception.what());
            SDL_Quit();
            return -1;
        }
        receiver.join();
        eventSender.join();
    }catch(std::exception &e){
        std::cerr << e.what() << std::endl;
        return 1;
    }catch(...){
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }
    return 0;
}
