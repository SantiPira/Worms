#include "../include/ClientSender.h"


ClientSender::ClientSender(Protocol& protocol, ProtectedQueue<std::string>* selfQueue) :
        m_Protocol(protocol), m_SelfQueue(selfQueue), m_KeepRunning(true) {}

void ClientSender::run() {
    try {
        while (m_KeepRunning) {
            std::string message = m_SelfQueue->pop();
        }
    } catch (const LibError& e) {
        m_KeepRunning.store(false);
    } catch (const ClosedQueue& cqe) {
        m_KeepRunning.store(false);
    } catch (...) {
        std::cout << "Error en ClientSender" << std::endl;
    }
}

void ClientSender::stop() {
    m_SelfQueue->close();
    m_KeepRunning.store(false);
}
