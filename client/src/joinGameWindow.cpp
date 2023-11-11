#include "joinGameWindow.h"

JoinGameWindow::JoinGameWindow(QWidget *parent, Juego* juego) : QWidget(parent), m_Juego(juego) {
    QVBoxLayout *layout = new QVBoxLayout();

    GameInfo gamesInfo = m_Juego->getGamesInfo();
        
    QListWidget *listWidget = new QListWidget();

    const std::vector<GameProperty> &partidas = gamesInfo.getGameProperties();
    for (const GameProperty &partida : partidas) {
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(partida.m_GameName) +
                                                         " - Jugadores: " + QString::number(partida.m_Players));
        listWidget->addItem(item);
    }

    layout->addWidget(listWidget);
    setLayout(layout);

        
    connect(listWidget, &QListWidget::itemClicked, this, &JoinGameWindow::slotJoinGame);
}

void JoinGameWindow::slotJoinGame() {
    
    this->close();
    
    m_Juego->joinGame();

}