#pragma once

#include <atomic>
#include "../../common_libs/include/Protocol.h"

class PruebaClient {
private:
    Protocol m_Protocol;
    std::atomic<bool> running;
public:
    PruebaClient(const char* hostname, const char* port);
    void start();
    ~PruebaClient() = default;
    PruebaClient(const PruebaClient&) = delete;
    PruebaClient(PruebaClient&&) = delete;
};