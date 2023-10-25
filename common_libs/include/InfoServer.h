#pragma once

#include <cstdint>
#include <vector>

class InfoServer {
private:
    uint8_t m_IdMessage;
    uint8_t m_Games;
    std::vector<uint16_t> m_Players;
public:
    explicit InfoServer(uint8_t idMessage, uint8_t games, std::vector<uint16_t> players);
    [[nodiscard]] uint8_t getIdMessage() const;
    [[nodiscard]] uint8_t getGames() const;
    [[nodiscard]] std::vector<uint16_t> getPlayers() const;

    ~InfoServer() = default;
    InfoServer(const InfoServer&) = delete;
    InfoServer(InfoServer&& other) = default;
};