#pragma once

#include <QMainWindow>
#include <QPushButton>
#include "mainWindow.h"
#include "waitingWindow.h"

class StartWindow : public QMainWindow {
public:
    StartWindow(QWidget *parent = nullptr);
private slots:
    void startGame();
private:
    QPushButton *startButton;
    MainWindow *mainWindow;
    WaitingWindow *waitingWindow;
public:
    Protocol* getProtocol();
    int getIdPlayer() const;
    int getCantPlayers() const;
    WaitingWindow* getWaitingWindow();

};