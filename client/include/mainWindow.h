#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include "client_juego.h"
#include "waitingWindow.h"

class MainWindow : public QWidget {
private:
    Juego* juego;
    std::atomic<bool> m_Lobby;
public:
    explicit MainWindow(QWidget *parent = 0, WaitingWindow* waitingWindow = 0);
    Protocol* getProtocol();
    bool isLobby();
    ~MainWindow() override;

    int getCantPlayers() const;
    int getIdPlayer() const;

private slots:
    void switchToGame();
    
private:
    // Creo los widgets asignandole un padre
    QLabel labelOut;
    QPushButton buttonConnect;
    QLineEdit inputPort;
    QLineEdit inputServer;

    WaitingWindow* m_WaitingWindow;

};

#endif // MAINWINDOW_H