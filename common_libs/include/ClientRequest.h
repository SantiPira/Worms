#pragma once

#include <cstdint>

class ClientRequest {
private:
    uint8_t m_Action;
public:
    ClientRequest(uint8_t action);
    ClientRequest();
    [[nodiscard]] uint8_t getAction() const;
    void setAction(uint8_t action);
    [[nodiscard]] bool isQuit() const;

    ~ClientRequest() = default;
    ClientRequest(ClientRequest&& other) = default;
};