#pragma once

#include <cstdint>
#include "ActionFromClient.h"

class ClientResponse {
private:
    ActionFromClient m_Action;
public:
    ClientResponse(ActionFromClient action);
    ClientResponse();
    [[nodiscard]] ActionFromClient getAction() const;
    void setAction(ActionFromClient action);
    [[nodiscard]] bool isQuit() const;

    ~ClientResponse() = default;
    ClientResponse(ClientResponse&& other) = default;
};