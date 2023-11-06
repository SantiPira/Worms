#include "../include/TurnHandler.h"

#define MAX_TURN_SECONDS 120

TurnHandler::TurnHandler(int idPlayer, int players) : idCurrentPlayer(idPlayer), m_Players(players),
    m_StartTime(std::chrono::system_clock::now()), m_MaxTurnSeconds(MAX_TURN_SECONDS) {}

bool TurnHandler::isValidTurn() {
    return difftime(std::chrono::system_clock::now().time_since_epoch().count(),
                    m_StartTime.time_since_epoch().count()) < m_MaxTurnSeconds;
}

void TurnHandler::nextTurn() {
    idCurrentPlayer = idCurrentPlayer % m_Players;
    m_StartTime = std::chrono::system_clock::now();
}

int TurnHandler::getCurrentPlayer() const {
    return idCurrentPlayer;
}



