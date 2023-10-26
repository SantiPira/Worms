#include "../include/ClientRequest.h"

ClientRequest::ClientRequest(uint8_t action) : m_Action(action) {}

ClientRequest::ClientRequest() : m_Action(0) {}

uint8_t ClientRequest::getAction() const {
    return m_Action;
}

void ClientRequest::setAction(uint8_t action) {
    m_Action = action;
}

bool ClientRequest::isQuit() const {
    return m_Action == 0;
}

