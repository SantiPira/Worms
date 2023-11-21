#include <iostream>
#include <QApplication>
#include <SDL.h>
#include "mainWindow.h"
#include "GameClient.h"
#include "ClientManager.h"
#include "messages/server/GameUpdate.h"
#include "waitingWindow.h"

int main(int argc, char *argv[]) {
    try{
        QApplication app(argc, argv);
        WaitingWindow* waitingWindow = new WaitingWindow();
        MainWindow window_connect(nullptr, waitingWindow);
        window_connect.show();
        app.exec();
        try {
            ClientManager clientManager(window_connect.getProtocol(), window_connect.getIdPlayer(), window_connect.getCantPlayers(), waitingWindow);
            clientManager.init();
            //TODO: tener una ventana de QT con fin de juego

            //TODO: Ver tema exceptions y manejo del main / ClientManager
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
