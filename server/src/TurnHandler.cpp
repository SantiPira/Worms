#include "../include/TurnHandler.h"


TurnHandler::TurnHandler(int idPlayer, std::vector<int> idPlayers) : idCurrentPlayer(idPlayer),
    m_StartTime(std::chrono::system_clock::now()), m_MaxTurnSeconds(10) {
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



