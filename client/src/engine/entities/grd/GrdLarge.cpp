#include "engine/entities/grd/GrdLarge.h"

GrdLarge::GrdLarge(SDL_Renderer *renderer, float posX, float posY, float w, float h) : m_Renderer(renderer),
    m_GrdLWidth(WorldScale::toPixel(w)), m_GrdLHeight(WorldScale::toPixel(h)) {

    m_DestGrdLRect = {static_cast<int>(WorldScale::worldToPixelX(posX, m_GrdLWidth)),
                      static_cast<int>(WorldScale::worldToPixelY(posY, m_GrdLHeight)),
                      static_cast<int>(m_GrdLWidth), static_cast<int>(m_GrdLHeight)};
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

SDL_Rect& GrdLarge::getGrdlRect() {
    return this->m_DestGrdLRect;
}
