#include "engine/entities/grd/GrdLarge.h"

GrdLarge::GrdLarge(SDL_Renderer *renderer, int posX, int posY) : m_Renderer(renderer) {
    m_DestGrdLRect = SDL_Rect{static_cast<int>(WorldScale::getPixelScale(posX)),
                              static_cast<int>(512 - WorldScale::getPixelScale(posY)), 256, 27};
    //m_DestGrdLRect = SDL_Rect{static_cast<int>((posX / 2) * 25.6), static_cast<int>(posY * 25.6), 256, 20};
}

void GrdLarge::init() {
    BlendMode blendMode = {false, 128, 128, 192};
    m_GrdLTexture = new Texture(std::filesystem::current_path().concat(Map_Grdl_Large_Horizontal.c_str()).c_str(),
                                m_Renderer, blendMode);
    m_GrdLTexture->init();
}

void GrdLarge::render() {
    m_GrdLTexture->render(&m_DestGrdLRect, false);
}

void GrdLarge::release() {
    m_GrdLTexture->release();
    delete m_GrdLTexture;
}

