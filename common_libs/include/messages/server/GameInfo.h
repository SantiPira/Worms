#pragma once

#include <cstdint>
#include <vector>
#include <utility>
#include <string>
#include "messages/server/InitGameEnum.h"

struct GameProperty {
    int m_idGame;
    std::string m_GameName;
    std::string m_MapName;
    int m_Players;
};

class GameInfo {
private:
    InitGameEnum m_IdAction;
    std::vector<GameProperty> m_GameProperties;
public:
    GameInfo(InitGameEnum idAction, std::vector<GameProperty> gameProperties);
    GameInfo();
    [[nodiscard]] InitGameEnum getIdAction() const;
    [[nodiscard]] std::vector<GameProperty> getGameProperties() const;
    //setter
    void setIdAction(InitGameEnum idAction);
    void setGameProperties(std::vector<GameProperty> gameProperties);

    ~GameInfo() = default;
    GameInfo(GameInfo&& other) = default;
    GameInfo(const GameInfo& other) = default;
};