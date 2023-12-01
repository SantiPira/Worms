#include "client_receiver.h"

ClientReceiver::ClientReceiver(Protocol& protocol, ProtectedQueue<GameUpdate>& gameUpdates,
                               EventSender& eventSender, int idPlayer): m_Protocol(protocol),
    m_GameUpdates(gameUpdates), m_EventSender(eventSender), m_IdPlayer(idPlayer) {}

void  ClientReceiver::run() {
    while (!m_Protocol.isClosed()) {
        auto gameUpdate = m_Protocol.recvGameUpdate();
        if (gameUpdate.m_TurnInfo != INVALID_ACTION) {
            manageTurn(std::ref(gameUpdate), gameUpdate.player_id);
        } else {
            m_GameUpdates.push(gameUpdate);
        }
    }
}

void ClientReceiver::manageTurn(const GameUpdate& turnInfo, int id) {
    if (turnInfo.m_TurnInfo == START_TURN) {
        m_GameUpdates.push(turnInfo);
    }
    if (id != m_IdPlayer) {
        if (turnInfo.m_TurnInfo == START_TURN) {
            std::cout << "Player " << id << " started turn" << std::endl;
        } else if (turnInfo.m_TurnInfo == END_TURN) {
            std::cout << "Player " << id << " ended turn" << std::endl;
        }
        return;
    }
    if (turnInfo.m_TurnInfo == START_TURN) {
        m_EventSender.setItsMyTurn(true);
    } else if (turnInfo.m_TurnInfo == END_TURN) {
        m_EventSender.setItsMyTurn(false);
    } else {
        throw std::runtime_error("Invalid turn info");
    }
}
