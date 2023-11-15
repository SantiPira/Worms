#pragma once

#include <SDL_render.h>
#include "utils/WorldScale.h"
#include "engine/graphics/Texture.h"
#include "engine/entities/TexturePaths.h"
#include "resources/GrdEnum.h"
#include <filesystem>

class GrdLarge {
 private:
    SDL_Renderer* m_Renderer;
    Texture* m_GrdLTexture{};
    SDL_Rect m_DestGrdLRect{};
    float m_GrdLWidth = 256.0f;
    float m_GrdLHeight = 27.0f;

 public:
    GrdLarge(SDL_Renderer* renderer, float posX, float posY);

    void init();
    void release();
    void render();
};