#include "engine/graphics/Texture.h"

Texture::Texture(std::string path, SDL_Renderer *renderer) : m_Path(std::move(path)),
                                                             m_Renderer(renderer),
                                                             m_SourceRect(),
                                                             m_Texture(nullptr) {}
void Texture::init() {
    SDL_Surface *surfaceTemp = IMG_Load(m_Path.c_str());
    m_Texture = SDL_CreateTextureFromSurface(m_Renderer, surfaceTemp);
    SDL_QueryTexture(m_Texture, nullptr, nullptr, &m_SourceRect.w, &m_SourceRect.h);
    SDL_FreeSurface(surfaceTemp);
}

void Texture::setSourceRect(const SDL_Rect *rect) {
    m_SourceRect.x = rect->x;
    m_SourceRect.x = rect->x;
    m_SourceRect.w = rect->w;
    m_SourceRect.h = rect->h;
}

void Texture::render(const SDL_Rect *destRect) const {
    assert(m_Texture != nullptr && "Texture is not initialized, try to call to Init first");

    SDL_RenderCopy(m_Renderer, m_Texture, &m_SourceRect, destRect);
}

void Texture::release() {
    SDL_DestroyTexture(m_Texture);
    m_Texture = nullptr;
}
