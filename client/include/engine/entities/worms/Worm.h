#pragma once

#include <SDL_render.h>
#include "../graphics/Animation.h"
#include "../graphics/Texture.h"

class Worm {
private:
    SDL_Renderer* m_Renderer;
    Animation* m_WormAnimation;
    SDL_Rect m_DestWormRect;
    float m_WormXPosition;
public:
    Worm(SDL_Renderer* renderer);
    void init();
    void release();
    void update(double elapsedSeconds);
    void render();
};