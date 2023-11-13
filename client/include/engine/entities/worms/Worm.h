#pragma once

#include <SDL_render.h>
#include "SpritesEnum.h"
#include "engine/graphics/Animation.h"
#include "engine/entities/TexturePaths.h"
#include "engine/utils/WorldScale.h"
#include "messages/server/GameUpdate.h"
#include "messages/user_actions/Weapon.h"
#include <filesystem>
#include <unordered_map>

class Worm {
private:
    SDL_Renderer* m_Renderer;
    Animation* m_WormAnimation;
    std::unordered_map<SpritesEnum, Animation*> m_SpritesMap;
    SDL_Rect m_DestWormRect;
    int m_WormWidth;
    int m_WormHeight;
    float m_WormXPosition;
    BlendMode m_BlendMode;

public:
    Worm(SDL_Renderer* renderer, float posX, float posY);

    void init();
    void release();
    void update(double elapsedSeconds, const GameUpdate& gameUpdate);
    void render();

    GameAction m_Dir;
    Animation* m_CurrentAnimation;
};