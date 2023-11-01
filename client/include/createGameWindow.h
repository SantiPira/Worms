#ifndef CREATEGAMEWINDOW_H
#define CREATEGAMEWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDebug>
#include <QComboBox>

class CreateGameWindow : public QWidget {
public:
    CreateGameWindow(QWidget *parent = 0);

private:
    QPushButton buttonCreateGame;
    QLineEdit editGameName;
    QComboBox *comboBoxMapa;
    QComboBox *comboBoxPlayers;

public slots:
    void slotCreateGame();
};

#endif // CREATEGAMEWINDOW_H