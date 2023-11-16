#pragma once

#include <SDL_render.h>
#include "SpritesEnum.h"
#include "utils/WorldScale.h"
#include "engine/graphics/Animation.h"
#include "engine/entities/TexturePaths.h"
#include "messages/server/GameUpdate.h"
#include "messages/user_actions/Weapon.h"
#include <filesystem>
#include <unordered_map>

class Worm {
 private:
    SDL_Renderer* m_Renderer;
    std::unordered_map<SpritesEnum, std::unique_ptr<Animation>> m_SpritesMap;
    float m_WormXPosition;
    float m_WormYPosition;
    SpritesEnum m_CurrentSprite;
    float m_Widht;
    float m_Height;
    GameAction m_Dir;

private:
    std::unique_ptr<Animation> getWaccuseAnimation();
    std::unique_ptr<Animation> getWaccuseAxeAnimation();

 public:
    Worm(SDL_Renderer *renderer, float posX, float posY, float d, float d1);

    void init();
    void update(double elapsedSeconds, const GameUpdate& gameUpdate);
    void render();

    ~Worm() = default;
};