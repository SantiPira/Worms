#include "mapEditor.h"
#include "dragAndDrop.h"
#include "backgroundItem.h"

MapEditor::MapEditor(QWidget *parent) : QMainWindow(parent), currentBackground(nullptr)
{
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 513, 513);
    view = new QGraphicsView(scene, this);

    view->setSceneRect(scene->sceneRect());

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setRenderHint(QPainter::Antialiasing, true);
    view->setRenderHint(QPainter::SmoothPixmapTransform, true);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    view->setFixedSize(513, 513);

    setCentralWidget(view);

    QPushButton *addBeamButton = new QPushButton("Add Beam", this);
    QPushButton *addSpawnButton = new QPushButton("Add Spawn", this);

    QComboBox *background = new QComboBox(this);
    background->addItem(QIcon("resources/Fondos/cielo.png"), "Sky");
    background->addItem("City");
    background->addItem("Forest");

    background->setStyleSheet("QComboBox {"
                                      "border: 1px solid gray;"
                                      "border-radius: 3px;"
                                      "padding: 1px 18px 1px 3px;"
                                      "min-width: 6em;}"
                                      "QComboBox::drop-down {"
                                      "subcontrol-origin: padding;"
                                      "subcontrol-position: top right;"
                                      "width: 15px;}");

    background->setFixedWidth(150);                                  

    connect(addBeamButton, &QPushButton::clicked, this, &MapEditor::addBeam);
    connect(addSpawnButton, &QPushButton::clicked, this, &MapEditor::addSpawn);
    connect(background, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MapEditor::backgroundSelection);


    addBeamButton->setFixedSize(100, 30);
    addSpawnButton->setFixedSize(100, 30);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(addBeamButton);
    layout->addWidget(addSpawnButton);
    layout->addWidget(background);
    layout->addStretch();
    layout->addWidget(view);

    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);

    resize(800, 600);

    setCentralWidget(widget);
}

void MapEditor::addBeam()
{
    QPixmap beamPixmap("resources/Weapons/grdl4.png"); 
    DragAndDrop *beamItem = new DragAndDrop(beamPixmap, 1, scene);
    scene->addItem(beamItem);
}

void MapEditor::addSpawn()
{
    QPixmap spawnPixmap("resources/Worms/worm-editor.png"); 
    DragAndDrop *spawnItem = new DragAndDrop(spawnPixmap, 0.1, scene);
    scene->addItem(spawnItem);
}

void MapEditor::backgroundSelection(int index)
{
    QPixmap backgroundPixmap;

    switch (index) {
        case 0:
            backgroundPixmap = QPixmap("resources/Fondos/cielo.png");
            break;
        case 1:
            //backgroundPixmap = QPixmap(".png");
            break;
        case 2:
            //backgroundPixmap = QPixmap(".png");
            break;
        default:
            break;
    }

    if (currentBackground) {
        currentBackground->setPixmap(backgroundPixmap);
    } else {
        currentBackground = new BackgroundItem(backgroundPixmap, 0.3);
        scene->addItem(currentBackground);
    }
}