#include "engine/entities/worms/Worm.h"

Worm::Worm(SDL_Renderer *renderer, float posX, float posY) : m_Renderer(renderer), m_WormXPosition(posX),
    m_BlendMode({true, 128, 128, 192}) {
    m_DestWormRect = SDL_Rect{static_cast<int>(WorldScale::getPixelScale(posX)),
                              static_cast<int>(WorldScale::getPixelScale(posY)), 26, 26};
}

void Worm::init() {
    //TODO: Enum for paths and sprites actions
    //TODO: Worms::WORM_WALKING_SPRITESHEET_PATH
    m_WormAnimation = new Animation(std::filesystem::current_path().concat(Worm_Sprite_Waccuse.c_str()).c_str(),
                                    m_Renderer, 36, 2, 60, 60, m_BlendMode);
    m_WormAnimation->init();
}

void Worm::release() {
    m_WormAnimation->release();
    delete m_WormAnimation;
}

void Worm::update(double elapsedSeconds, float posX, float posY) {
    m_WormAnimation->update(elapsedSeconds);
    m_DestWormRect.x = static_cast<int>(WorldScale::getPixelScale(posX));
    int m = 512 / 2;
    int pixelScale = static_cast<int>(WorldScale::getPixelScale(posY));
    if (pixelScale > m) {
        int diff = pixelScale - m;
        m_DestWormRect.y = m - diff;
    } else {
        m_DestWormRect.y = pixelScale;
    }
}

void Worm::render() {
    m_WormAnimation->render(&m_DestWormRect, true);
}
