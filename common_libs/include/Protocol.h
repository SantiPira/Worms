#pragma once

#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#include <netinet/in.h>
#include "liberror.h"
#include "socket.h"
#include <functional>
#include "messages/server/GameInfo.h"

class Protocol {
private:
    Socket socket;
    bool wasClosed;
private:
    /* private methods don't use them, and if you do it use wisely */
    void sendByte(uint8_t byte);
    void sendTwoBytes(uint16_t bytes);
    void sendString(const std::string& message);
    uint8_t recvByte();
    uint16_t recvTwoBytes();
    std::string recvString();
public:
    explicit Protocol(Socket socket);
    Protocol(const std::string& hostname, const std::string& servname);
    void recvGameInfo(GameInfo& gameInfo);
    void sendGameInfo(GameInfo& gameInfo);

    bool isClosed() const;
    void close();
    void shutdown(int mode);
    ~Protocol();
    Protocol(const Protocol&) = delete;
};
