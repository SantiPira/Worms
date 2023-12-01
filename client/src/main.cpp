// main.cpp
#include <iostream>
#include <QApplication>
#include "messages/server/GameUpdate.h"
#include "waitingWindow.h"
#include "StartWindow.h"
#include "ClientManager.h"

int main(int argc, char *argv[]) {
    try {
        QApplication app(argc, argv);
        StartWindow startWindow;
        startWindow.show();
        app.exec();
        try {
            ClientManager clientManager(startWindow.getProtocol(), startWindow.getIdPlayer(),
                                        startWindow.getCantPlayers(), startWindow.getWaitingWindow());
            clientManager.init();
            //TODO: tener una ventana de QT con fin de juego

            //TODO: Ver tema exceptions y manejo del main / ClientManager
        } catch (std::exception &exception) {
            fprintf(stderr, "%s", exception.what());
            SDL_Quit();
            return -1;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }
    return 0;
}