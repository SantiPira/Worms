#include <iostream>
#include <QApplication>
#include "mainWindow.h"

int main(int argc, char *argv[]) {
    try{

        QApplication app(argc, argv);
        
        MainWindow window_connect;
        window_connect.show();

        return app.exec();
    }catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }catch(...){
        std::cerr << "Unknown exception" << std::endl;
    }
}
