#pragma once

#include <cstdint>
#include "ActionFromClient.h"

class ClientInitGame {
protected:
    ActionFromClient m_Action;
    int m_IdGame;
    std::string m_GameName;
    std::string m_MapName;
    int m_Players{};
public:
    ClientInitGame(ActionFromClient action, int idGame, std::string gameName, std::string mapName, int players);
    ClientInitGame();
    /*Getters and Setter*/
    [[nodiscard]] ActionFromClient getAction() const;
    void setAction(ActionFromClient action);
    [[nodiscard]] int getIdGame() const;
    void setIdGame(int id);
    [[nodiscard]] std::string getGameName() const;
    void setGameName(std::string gameName);
    [[nodiscard]] std::string getMapName() const;
    void setMapName(std::string mapName);
    [[nodiscard]] int getPlayers() const;
    void setPlayers(int players);

    [[nodiscard]] bool isQuit() const;

    ~ClientInitGame() = default;
    ClientInitGame(ClientInitGame&& other) = default;
};