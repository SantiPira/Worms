#include "client_receiver.h"

ClientReceiver::ClientReceiver(Protocol& protocol, ProtectedQueue<GameUpdate>& gameUpdates): m_Protocol(protocol),
    m_GameUpdates(gameUpdates) {}

void  ClientReceiver::run() {
    while (!m_Protocol.isClosed()) {
        auto gameUpdate = m_Protocol.recvGameUpdate();
        m_GameUpdates.push(gameUpdate);
    }
}
