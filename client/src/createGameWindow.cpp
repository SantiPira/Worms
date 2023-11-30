#include "createGameWindow.h"

CreateGameWindow::CreateGameWindow(QWidget *parent, Juego* juego) : QWidget(parent), m_Juego(juego), buttonCreateGame("Iniciar Partida") {
    QVBoxLayout* layoutV = new QVBoxLayout();

    setWindowTitle("Creacion de partidas");
    buttonCreateGame.setStyleSheet("font-size: 12pt; spacing: 10px; margin: 10px; padding: 10px; border: 2px solid black; background-color: black; color: white; width: 100px; height: 50px;");
    buttonCreateGame.setCursor(QCursor(Qt::PointingHandCursor)); // Cambia el cursor al pasar el ratón
    buttonCreateGame.setStyleSheet("QPushButton:hover { background-color: #555; }"); // Cambia el color al pasar el ratón
    resize(300, 200);

    setStyleSheet("QPushButton { font-size: 16px; background-color: #3498db; color: #ffffff; }"
                  "QLabel { font-size: 14px; }");

    // Crear un desplegable para el campo "Mapa"
    comboBoxMapa = new QComboBox();
    comboBoxMapa->addItem("Mapa 1");
    comboBoxMapa->addItem("Mapa 2");
    comboBoxMapa->addItem("Mapa 3");

    // Agregar elementos al diseño vertical
    layoutV->addWidget(new QLabel("Mapa:"));
    layoutV->addWidget(comboBoxMapa);

    layoutV->addWidget(new QLabel("Nombre de la partida:"));
    layoutV->addWidget(&this->editGameName);

    // Crear widget para name del player
    editPlayerName.setPlaceholderText("Nombre del jugador");
    layoutV->addWidget(&editPlayerName);

    comboBoxPlayers = new QComboBox();
    comboBoxPlayers->addItem("1");
    comboBoxPlayers->addItem("2");
    comboBoxPlayers->addItem("4");
    comboBoxPlayers->addItem("6");

    layoutV->addWidget(new QLabel("Cantidad de jugadores:"));
    layoutV->addWidget(comboBoxPlayers);

    layoutV->addWidget(&buttonCreateGame);

    setLayout(layoutV);

    connect(&buttonCreateGame, &QPushButton::clicked, this, &CreateGameWindow::slotCreateGame);
}

void CreateGameWindow::slotCreateGame() {
    qDebug() << "Botón 'Iniciar Partida' presionado.";

    //Me guardo el mapa, el nombre de la partida y la cantidad de jugadores
    QString mapa_seleccionado = this->comboBoxMapa->currentText();
    QString name = this->editGameName.text();
    QString amountPlayers = this->comboBoxPlayers->currentText();
    QString playerName = this->editPlayerName.text();

    m_Juego->createGame(mapa_seleccionado.toStdString(), name.toStdString(), playerName.toStdString(),
                        amountPlayers.toStdString());
    this->close();
}