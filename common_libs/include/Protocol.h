#pragma once

#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#include <netinet/in.h>
#include "liberror.h"
#include "socket.h"
#include "messages/server/to_client/InfoServer.h"
#include "messages/server/from_client/CreateGame.h"


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
    /* private methods don't use them, and if you do it use wisely */

    void recvMessage(std::string& message);
    void recvClientInitGame(ClientInitGame& clientInitGame);
    /* end private methods don't use */
    explicit Protocol(Socket socket);
    Protocol(const std::string& hostname, const std::string& servname);
    void sendMessage(InfoServer& infoServer);
    bool isClosed() const;
    void close();
    void shutdown(int mode);

    ~Protocol();
    Protocol(const Protocol&) = delete;

    void recvServerInfo(InfoServer& server);
};
