#include "client_receiver.h"

ClientReceiver::ClientReceiver(Protocol& protocol, ProtectedQueue<std::string>& gameUpdates): m_Protocol(protocol),
    m_GameUpdates(gameUpdates) {}

void  ClientReceiver::run() {
    while (!m_Protocol.isClosed()) {
        std::string gameUpdate = m_Protocol.recvUpdateGame();
        m_GameUpdates.push(gameUpdate);
    }
}
