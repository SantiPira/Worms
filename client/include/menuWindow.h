#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDebug>

class MenuWindow : public QWidget {
public:
    MenuWindow(QWidget *parent = 0);

private:
    QPushButton buttonCreate;
    QPushButton buttonJoin;

public slots:
    void slotUnirsePartida();
    void slotCrearPartida();
};

#endif // MENUWINDOW_H