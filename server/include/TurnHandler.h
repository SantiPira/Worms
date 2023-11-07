#pragma once


#include <chrono>
class TurnHandler {
private:
    int idCurrentPlayer;
    int m_Players;
    std::chrono::time_point<std::chrono::system_clock> m_StartTime;
    std::chrono::time_point<std::chrono::system_clock> m_EndTime;
    double m_MaxTurnSeconds;
public:
    explicit TurnHandler(int idPlayer, int players);

    void start();
    bool isValidTurn();
    void nextTurn();
    [[nodiscard]] int getCurrentPlayer() const;

    ~TurnHandler() = default;
    TurnHandler(const TurnHandler&) = delete;
    TurnHandler(TurnHandler&& other) = delete;


};

