#pragma once

#include <string>
#include <SDL_rect.h>
#include "engine/graphics/Texture.h"
#include <filesystem>

struct WaccuseWalk {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/waccuse.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 36;
    int distanceBetweenFrames = 60;
    int frameWidth = 22;
    int frameHeight = 26;
    float duration = 2.0f;
    SDL_Rect srcRect = {20, 17, 22, 26};
    int initYSprite = 17;
};


struct WaccuseAxe {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/waxebk2.png");
    BlendMode blendMode = {true, 192, 192, 128};
    int frames = 7;
    int distanceBetweenFrames = 104;
    int frameWidth = 41;
    int frameHeight = 39;
    float duration = 2.0f;
    SDL_Rect srcRect = {39, 26, 41, 39};
    int initYSprite = 26;
};

struct WaccuseJumping {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/waccuseu.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 36;
    int distanceBetweenFrames = 60;
    int frameWidth = 22;
    int frameHeight = 26;
    float duration = 2.0f;
    SDL_Rect srcRect = {20, 17, 18, 30};
    int initYSprite = 17;
};