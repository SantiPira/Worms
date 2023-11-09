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
    int m_FrameHeight;
    int m_FrameWidth;

public:
    Animation(std::string path, SDL_Renderer *renderer, int frames, float duration, int frameHeight, int frameWidth);

    void init();
    void release();
    void update(double elapsedSeconds);
    void render(const SDL_Rect *destRect) const;
};
