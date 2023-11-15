#pragma once

#include <SDL_render.h>
#include <string>
#include "Texture.h"

class Animation {
 private:
    Texture *m_Texture;
    int m_Frames;
    float m_Duration;
    double m_CurrentTime;
    SDL_Rect m_SourceRect;
    int m_InitYSprite;
    SDL_Rect m_DestRect;
    int m_FrameHeight;
    int m_FrameWidth;
    int m_Width;
    int m_Height;
    float m_PosX;
    float m_PosY;

public:
    Animation(std::string path, SDL_Renderer *renderer, int frames, float duration, SDL_Rect srcRect, int initYSprite,
              int frameHeight, int frameWidth, BlendMode blendMode, int width, int height, float posX, float posY);

    void init();
    void release();
    void update(double elapsedSeconds);
    void render(bool isFlip) const;

    int getWormWidth() const;

    int getWormHeight() const;

    void setPositions(float x, float y);
};
