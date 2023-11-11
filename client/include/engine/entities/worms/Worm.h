#pragma once

#include <SDL_render.h>
#include "engine/graphics/Animation.h"
#include "engine/entities/TexturePaths.h"
#include "engine/utils/WorldScale.h"
#include <filesystem>

class Worm {
private:
    SDL_Renderer* m_Renderer;
    Animation* m_WormAnimation;
    SDL_Rect m_DestWormRect;
    float m_WormXPosition;
    BlendMode m_BlendMode;

public:
    Worm(SDL_Renderer* renderer, float posX, float posY);

    void init();
    void release();
    void update(double elapsedSeconds, float posX, float posY);
    void render();
};