#pragma once

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QDebug>
#include <QObject>

class WaitingWindow : public QWidget {
    public:
        WaitingWindow(QWidget *parent = 0);

    private:
        QLabel *etiqueta;
    
};