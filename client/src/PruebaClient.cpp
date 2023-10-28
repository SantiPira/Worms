#include <functional>
#include "../include/PruebaClient.h"

PruebaClient::PruebaClient(const char *hostname, const char *port) : m_Protocol(hostname, port) {}

void PruebaClient::start() {
    InfoServer m_ServerInfo;
    m_Protocol.recvServerInfo(std::ref(m_ServerInfo));
    std::string m_Command;
    std::getline(std::cin, m_Command);
    while (m_Command != "exit") {
        m_Protocol.sendByte(getAction(m_Command));
        std::getline(std::cin, m_Command);
    }
}

