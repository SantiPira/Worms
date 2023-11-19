#include "client_receiver.h"

ClientReceiver::ClientReceiver(Protocol& protocol, ProtectedQueue<GameUpdate>& gameUpdates,
                               EventSender& eventSender, int idPlayer): m_Protocol(protocol),
    m_GameUpdates(gameUpdates), m_EventSender(eventSender), m_IdPlayer(idPlayer) {}

void  ClientReceiver::run() {
    while (!m_Protocol.isClosed()) {
        auto gameUpdate = m_Protocol.recvGameUpdate();
        if (!manageTurn(gameUpdate.m_SelfCondition, gameUpdate.player_id)) {
            m_GameUpdates.push(gameUpdate);
        }
    }
}

bool ClientReceiver::manageTurn(GameAction action, int id) {
    if (id == m_IdPlayer) {
        if (action == GameAction::END_TURN) {
            m_EventSender.setItsMyTurn(false);
            return true;
        } else if (action == GameAction::START_TURN) {
            m_EventSender.setItsMyTurn(true);
            return true;
        }
    }
    return false;
}
