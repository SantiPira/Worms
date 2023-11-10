#pragma once

#include <SDL_render.h>
#include "engine/graphics/Texture.h"
#include "engine/entities/TexturePaths.h"
#include "engine/utils/WorldScale.h"
#include "resources/GrdEnum.h"
#include <filesystem>

class GrdLarge {
 private:
    SDL_Renderer* m_Renderer;
    Texture* m_GrdLTexture;
    SDL_Rect m_DestGrdLRect;
    //float m_GrdLXPosition;
    //BlendMode m_BlendMode;

 public:
    GrdLarge(SDL_Renderer* renderer, int posX, int posY);

    void init();
    void release();
    //void update(double elapsedSeconds);
    void render();
};