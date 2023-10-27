#include "../../../../include/messages/server/from_client/ClientResponse.h"

ClientResponse::ClientResponse(ActionFromClient action) : m_Action(action) {}

ClientResponse::ClientResponse() : m_Action(ActionFromClient::FC_INVALID) {}

ActionFromClient ClientResponse::getAction() const {
    return m_Action;
}

void ClientResponse::setAction(ActionFromClient action) {
    m_Action = action;
}

bool ClientResponse::isQuit() const {
    return m_Action == ActionFromClient::FC_CREATE_GAME || m_Action == ActionFromClient::FC_QUIT;
}

