#pragma once

#include <cstdint>
#include <vector>
#include "ActionToClient.h"

class InfoServer {
private:
    ActionToClient m_IdAction;
    uint8_t m_Games;
    std::vector<uint16_t> m_Players;
public:
    explicit InfoServer(ActionToClient idAction, uint8_t games, std::vector<uint16_t> players);
    [[nodiscard]] ActionToClient getIdAction() const;
    [[nodiscard]] uint8_t getGames() const;
    [[nodiscard]] std::vector<uint16_t> getPlayers() const;

    //setter
    void setIdAction(ActionToClient idAction);
    void setGames(uint8_t games);
    void setPlayers(std::vector<uint16_t> players);

    ~InfoServer() = default;
    InfoServer(const InfoServer&) = delete;
    InfoServer(InfoServer&& other) = default;
};