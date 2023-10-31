#include "createGameWindow.h"

CreateGameWindow::CreateGameWindow(QWidget *parent) : QWidget(parent), buttonCreateGame("Iniciar Partida") {
    QVBoxLayout* layoutV = new QVBoxLayout();

    setWindowTitle("Creacion de partidas");
    buttonCreateGame.setStyleSheet("font-size: 12pt; spacing: 10px; margin: 10px; padding: 10px; border: 2px solid black; background-color: black; color: white; width: 100px; height: 50px;");
    buttonCreateGame.setCursor(QCursor(Qt::PointingHandCursor)); // Cambia el cursor al pasar el ratón
    buttonCreateGame.setStyleSheet("QPushButton:hover { background-color: #555; }"); // Cambia el color al pasar el ratón
    resize(300, 200);

    setStyleSheet("QPushButton { font-size: 16px; background-color: #3498db; color: #ffffff; }"
                  "QLabel { font-size: 14px; }");

    layoutV->addWidget(new QLabel("Mapa:"));
    layoutV->addWidget(&this->editGameMap);

    layoutV->addWidget(new QLabel("Nombre de la partida:"));
    layoutV->addWidget(&this->editGameName);

    layoutV->addWidget(new QLabel("Cantidad de jugadores:"));
    layoutV->addWidget(&this->editGameAmountPlayers);

    layoutV->addWidget(&buttonCreateGame);

    setLayout(layoutV);

    connect(&buttonCreateGame, &QPushButton::clicked, this, &CreateGameWindow::slotCreateGame);
}

void CreateGameWindow::slotCreateGame() {
    qDebug() << "Botón 'Iniciar Partida' presionado.";

    //Me guardo el mapa, el nombre de la partida y la cantidad de jugadores
    QString map = this->editGameMap.text();
    QString name = this->editGameName.text();
    QString amountPlayers = this->editGameAmountPlayers.text();

    this->close();
}