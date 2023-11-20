#pragma once

#include <string>
#include <SDL_rect.h>
#include "engine/graphics/Texture.h"
#include <filesystem>

/* DOCUMENTACION
 * DeltaPosX y DeltaPosY corresponden a la correccion para mostrar el sprite segun la dimension de este ya que
 * existen sprites distintos, y habria que modificar el cuerpo del World para poder mandar desde el servidor el width y height
 * Y asi modelar usando WorldScale::toPixel(w o h) y renderizar el gusano segun las dimensaiones que esta tomando en el World
 * En este proyecto, a priori se utiliza un Worm dinamico pero que no cambia sus dimensiones a lo largo del juego*/
struct WaccuseIdle {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/waccuse.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 36;
    int distanceBetweenFrames = 60;
    int frameWidth = 26;
    int frameHeight = 41;
    float duration = 2.0f;
    SDL_Rect srcRect = {20, 17, 22, 26};
    int initYSprite = 17;
    float deltaPosX = 25.6f;
    float deltaPosY = 40.96f;
};

struct WaccuseWalk {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wwalk.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 15;
    int distanceBetweenFrames = 60;
    int frameWidth = 30;
    int frameHeight = 44;
    float duration = 0.3f;
    SDL_Rect srcRect = {11, 14, 28, 29};
    int initYSprite = 14;
    float deltaPosX = 25.6f;
    float deltaPosY = 40.96f;
};


struct WaccuseAxe {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/waxebk2.png");
    BlendMode blendMode = {true, 192, 192, 128};
    int frames = 7;
    int distanceBetweenFrames = 104;
    int frameWidth = 47;
    int frameHeight = 47;
    float duration = 2.0f;
    SDL_Rect srcRect = {39, 26, 41, 39};
    int initYSprite = 26;
    float deltaPosX = 47.0f;
    float deltaPosY = 51.0f;
};

struct WaccuseJumping {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/waccuseu.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 36;
    int distanceBetweenFrames = 60;
    int frameWidth = 26;
    int frameHeight = 41;
    float duration = 2.0f;
    SDL_Rect srcRect = {20, 17, 18, 30};
    int initYSprite = 17;
    float deltaPosX = 25.6f; // WIDTH WORLD WORM * 2 * 25.6
    float deltaPosY = 40.96f; // HEIGHT WORLD WORM * 2 * 25.6
};

struct WaccuseDie {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wdie.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 60;
    int distanceBetweenFrames = 60;
    int frameWidth = 47;
    int frameHeight = 53;
    float duration = 1.0f;
    SDL_Rect srcRect = {1, 7, 38, 40};
    int initYSprite = 7;
    float deltaPosX = 30.0f;
    float deltaPosY = 52.0f;
};

struct WaccuseGettingDamage {
    const std::string spritePath = std::filesystem::current_path().concat("/resources/Worms/wpbrtlk.png");
    BlendMode blendMode = {true, 128, 128, 192};
    int frames = 15;
    int distanceBetweenFrames = 60;
    int frameWidth = 26;
    int frameHeight = 41;
    float duration = 1.0f;
    SDL_Rect srcRect = {20, 17, 22, 26};
    int initYSprite = 17;
    float deltaPosX = 25.6f;
    float deltaPosY = 40.96f;
};

/*
struct SkySking {
    const std::string spritePath = "../../resources/Fondos/cielo.png"
    BlendMode blendMode = {false, 128, 128, 192};
    int frames = 1;
    int distanceBetweenFrames = 0;
    int frameWidth = 4096;
    int frameHeight = 2304;
    float duration = 1.0f;
    SDL_Rect srcRect = {0, 0, 512, 512};
    int initYSprite = 17;
    float deltaPosX = 25.6f;
    float deltaPosY = 40.96f;
};
*/
