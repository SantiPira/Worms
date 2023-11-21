#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QWidget>
#include <QComboBox>
#include <QString>
#include "backgroundItem.h"

class MapEditor : public QMainWindow
{

public:
    MapEditor(QWidget *parent = nullptr);

private slots:
    void addBeam();
    void addSpawn();
    void backgroundSelection(int index);

private:
    BackgroundItem *currentBackground;
    QGraphicsScene *scene;
    QGraphicsView *view;
};
