#include "messages/server/GameInfo.h"

GameInfo::GameInfo() : m_IdAction(InitGameEnum::INVALID) {}

GameInfo::GameInfo(InitGameEnum idAction, std::vector<GameProperty> gameProperties) : m_IdAction(idAction),
    m_GameProperties(std::move(gameProperties)) {}

void GameInfo::setIdAction(InitGameEnum idAction) {
    m_IdAction = idAction;
}

InitGameEnum GameInfo::getIdAction() const {
    return m_IdAction;
}

void GameInfo::setGameProperties(std::vector<GameProperty> gameProperties) {
    m_GameProperties = std::move(gameProperties);
}

std::vector<GameProperty> GameInfo::getGameProperties() const {
    return m_GameProperties;
}

