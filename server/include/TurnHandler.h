#pragma once

#include <chrono>
#include <vector>

class TurnHandler {
private:
    int idCurrentPlayer;
    std::vector<int> m_IdPlayers;
    std::chrono::time_point<std::chrono::system_clock> m_StartTime;
    std::chrono::time_point<std::chrono::system_clock> m_EndTime;
    double m_MaxTurnSeconds;
public:
    explicit TurnHandler(int idPlayer, std::vector<int> players);

    bool isValidTurn();
    void nextTurn();
    [[nodiscard]] int getCurrentPlayer() const;

    ~TurnHandler() = default;
    TurnHandler(const TurnHandler&) = delete;
    TurnHandler(TurnHandler&& other) = delete;


};

