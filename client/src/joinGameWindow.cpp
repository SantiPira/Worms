#include "joinGameWindow.h"

JoinGameWindow::JoinGameWindow(QWidget *parent, Juego* juego) : QWidget(parent), m_Juego(juego) {
    QVBoxLayout *layout = new QVBoxLayout();

    auto gamesInfo = m_Juego->getGamesInfo();
        
    QListWidget *listWidget = new QListWidget();

    const std::vector<GameProperty> &partidas = gamesInfo.getGameProperties();
    for (const GameProperty &partida : partidas) {
        m_GameProperties.insert(std::make_pair(partida.m_idGame, partida));
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(partida.m_GameName) +
                                                         " - Jugadores permitidos: " + QString::number(partida.m_Players)
                                                         + " - Jugadores conectados: " +
                                                         QString::number(partida.m_PlayersConnected));
        item->data(Qt::UserRole).setValue(partida.m_idGame);
        listWidget->addItem(item);
    }

    layout->addWidget(listWidget);
    setLayout(layout);

    connect(listWidget, &QListWidget::itemClicked, this, &JoinGameWindow::slotJoinGame);
}

void JoinGameWindow::slotJoinGame(QListWidgetItem *selectedItem) {
    idGame = selectedItem->data(Qt::UserRole).toInt();
    m_Juego->joinGame(idGame, m_GameProperties.at(idGame).m_Players);

    this->close();
}