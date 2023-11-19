#include "../include/TurnHandler.h"


TurnHandler::TurnHandler(int idPlayer, std::vector<int> idPlayers) : idCurrentPlayer(idPlayer),
    m_IdPlayers(std::move(idPlayers)), m_StartTime(std::chrono::system_clock::now()), m_MaxTurnSeconds(30) {}

bool TurnHandler::isValidTurn() {
//    double difftime1 = difftime(std::chrono::system_clock::now().time_since_epoch().count(),
//                                m_StartTime.time_since_epoch().count());
//    return difftime1 < m_MaxTurnSeconds;
    std::chrono::duration<double> elapsedSeconds = std::chrono::system_clock::now() - m_StartTime;
    return elapsedSeconds.count() < m_MaxTurnSeconds;
}

void TurnHandler::nextTurn() {
    int tempId = m_IdPlayers.at(idCurrentPlayer) + 1;
    if (tempId >= static_cast<int>(m_IdPlayers.size())) {
        tempId = 0;
    }
    idCurrentPlayer = tempId;
    m_StartTime = std::chrono::system_clock::now();
}

int TurnHandler::getCurrentPlayer() const {
    return idCurrentPlayer;
}



