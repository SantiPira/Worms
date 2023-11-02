#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include "client_juego.h"

class MainWindow : public QWidget {
private:
    Juego* juego;
public:
    explicit MainWindow(QWidget *parent = 0);
    Protocol* getProtocol();
private slots:
    void switchToGame();
    
private:
    // Creo los widgets asignandole un padre
    QLabel labelOut;
    QPushButton buttonConnect;
    QLineEdit inputPort;
    QLineEdit inputServer;

};

#endif // MAINWINDOW_H