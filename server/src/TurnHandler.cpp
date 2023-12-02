#include "../include/TurnHandler.h"


TurnHandler::TurnHandler(int idPlayer, std::vector<int> idPlayers, bool testMode) : idCurrentPlayer(idPlayer),
                                                                                    m_StartTime(std::chrono::system_clock::now()), m_MaxTurnSeconds(20), m_TestMode(testMode), m_EndGame(false) {
    m_IdPlayers = std::map<int, int>();
    for (int i = 0; i < static_cast<int>(idPlayers.size()); i++) {
        m_IdPlayers.insert(std::pair<int, int>(i, idPlayers.at(i)));
    }
}

bool TurnHandler::isValidTurn() {
    std::chrono::duration<double> elapsedSeconds = std::chrono::system_clock::now() - m_StartTime;
    return elapsedSeconds.count() < m_MaxTurnSeconds;
}

void TurnHandler::nextTurn(const std::vector<int>& wormsRemovedIds) {
    std::cout << "Turn prev id: " << idCurrentPlayer << std::endl;
    if (m_TestMode) {
        if (wormsRemovedIds.size() == m_IdPlayers.size()) {
            m_EndGame = true;
            return;
        }
    } else {
        if (wormsRemovedIds.size() == m_IdPlayers.size() - 1) {
            m_EndGame = true;
            return;
        }
    }
    for (auto& wormRemovedId : wormsRemovedIds) {
        for (auto& idPlayer : m_IdPlayers) {
            if (idPlayer.second == wormRemovedId) {
                m_IdPlayers.erase(idPlayer.first);
                break;
            }
        }
    }
    auto it = m_IdPlayers.find(idCurrentPlayer);
    if (it == m_IdPlayers.end()) {
        idCurrentPlayer = m_IdPlayers.begin()->second;
    } else {
        it++;
        if (it == m_IdPlayers.end()) {
            idCurrentPlayer = m_IdPlayers.begin()->second;
        } else {
            idCurrentPlayer = it->second;
        }
    }
    std::cout << "Turn next id: " << idCurrentPlayer << std::endl;
    m_StartTime = std::chrono::system_clock::now();
}

int TurnHandler::getCurrentPlayer() const {
    return idCurrentPlayer;
}

double TurnHandler::getSecondsPerTurn() const {
    return m_MaxTurnSeconds;
}

bool TurnHandler::isEndGame() const {
    return m_EndGame;
}



