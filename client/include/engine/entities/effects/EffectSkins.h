#pragma once

#include <string>
#include <SDL_rect.h>
#include "engine/graphics/Texture.h"
#include <filesystem>

struct GraveSkin {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Misc/grave1.png");
    BlendMode blendMode = {true, 192, 192, 128};
    int frames = 20;
    int distanceBetweenFrames = 60;
    int frameWidth = 26;
    int frameHeight = 41;
    float duration = 2.0f;
    SDL_Rect srcRect = {19, 4, 22, 32};
    int initYSprite = 4;
    float deltaPosX = 25.6f; // 1m = 25.6px
    float deltaPosY = 40.96f; // 1.6 m = 40.96px
};

struct BlobSkin {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Effects/blob.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 16;
    int distanceBetweenFrames = 64;
    int frameWidth = 22;
    int frameHeight = 22;
    float duration = 0.3f;
    SDL_Rect srcRect = {21, 21, 22, 22};
    int initYSprite = 21;
    float deltaPosX = 25.6f;
    float deltaPosY = 40.96f;
};
