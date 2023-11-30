#include "client_receiver.h"

ClientReceiver::ClientReceiver(Protocol& protocol, ProtectedQueue<GameUpdate>& gameUpdates,
                               EventSender& eventSender, int idPlayer): m_Protocol(protocol),
    m_GameUpdates(gameUpdates), m_EventSender(eventSender), m_IdPlayer(idPlayer) {}

void  ClientReceiver::run() {
    while (!m_Protocol.isClosed()) {
        auto gameUpdate = m_Protocol.recvGameUpdate();
        if (gameUpdate.m_TurnInfo != INVALID_ACTION) {
            manageTurn(gameUpdate.m_TurnInfo, gameUpdate.player_id);
        } else {
            m_GameUpdates.push(gameUpdate);
        }
    }
}

void ClientReceiver::manageTurn(GameAction turnInfo, int id) {
    if (id != m_IdPlayer) {
        if (turnInfo == START_TURN) {
            std::cout << "Player " << id << " started turn" << std::endl;
        } else if (turnInfo == END_TURN) {
            std::cout << "Player " << id << " ended turn" << std::endl;
        }
        return;
    }
    if (turnInfo == START_TURN) {
        m_EventSender.setItsMyTurn(true);
    } else if (turnInfo == END_TURN) {
        m_EventSender.setItsMyTurn(false);
    } else {
        throw std::runtime_error("Invalid turn info");
    }
}
