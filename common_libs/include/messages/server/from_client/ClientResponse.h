#pragma once

#include <cstdint>
#include "ActionFromClient.h"

class ClientResponse {
private:
    ActionFromClient m_Action;
    int idGame;
public:
    ClientResponse(ActionFromClient action);
    ClientResponse();
    [[nodiscard]] ActionFromClient getAction() const;
    void setAction(ActionFromClient action);

    [[nodiscard]] int getIdGame() const;
    void setIdGame(int id);

    [[nodiscard]] bool isQuit() const;

    ~ClientResponse() = default;
    ClientResponse(ClientResponse&& other) = default;
};