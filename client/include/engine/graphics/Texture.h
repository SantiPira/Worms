#pragma once

#include <string>
#include <SDL_render.h>
#include <SDL_image.h>
#include <assert.h>
#include <utility>

class Texture {
 private:
    std::string m_Path;
    SDL_Renderer* m_Renderer;
    SDL_Rect m_SourceRect;
    SDL_Texture* m_Texture;
 public:
    Texture(std::string path, SDL_Renderer* renderer);

    void init();
    void release();
    void setSourceRect(const SDL_Rect *rect);
    void render(const SDL_Rect *destRect) const;
};
