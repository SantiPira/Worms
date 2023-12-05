#include <iostream>
#include <QApplication>
#include <QMessageBox>
#include "messages/server/GameUpdate.h"
#include "StartWindow.h"
#include "ClientManager.h"

int main(int argc, char *argv[]) {
    try {
        #ifdef TEST 
            Juego juego(argv[1],argv[2]);
            std::string decision(argv[3]);
            if(decision == "create") {
                std::string players(argv[4]);
                juego.createGame(std::string("Mapa 1"), std::string("Mapa testing"), std::string("1"), players);
            } else if(decision == "join") {
                juego.joinGame(int(0),int(2),std::string("2"));
            } else {
                std::cout << "Undefined decision in testing mode\n";
                return -1;
            }
        #else
            QApplication app(argc, argv);
            StartWindow startWindow;
            startWindow.show();
            app.exec();
        #endif
        try {
            #ifdef TEST
                ClientManager clientManager(juego.getProtocol(), juego.getIdPlayer(), 
                                            juego.getPlayers());
            #else
                ClientManager clientManager(startWindow.getProtocol(), startWindow.getIdPlayer(),
                                            startWindow.getCantPlayers());
            #endif
            clientManager.init();
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