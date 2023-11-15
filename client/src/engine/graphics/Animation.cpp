#include "engine/graphics/Animation.h"

Animation::Animation(std::string path, SDL_Renderer *renderer, int frames, float duration, SDL_Rect srcRect,
                     int initYSprite, int frameHeight, int frameWidth, BlendMode blendMode,
                     int width, int height, float posX, float posY) :
                     m_Texture(new Texture(std::move(path), renderer, blendMode)),
                     m_Frames(frames), m_Duration(duration), m_CurrentTime(0.0f), m_SourceRect(srcRect),
                     m_InitYSprite(initYSprite), m_FrameHeight(frameHeight), m_FrameWidth(frameWidth), m_Width(width),
                     m_Height(height), m_PosX(posX), m_PosY(posY) {}

void Animation::init() {
    m_Texture->init();
    m_DestRect.x = m_PosX;
    m_DestRect.y = m_PosY;
    m_DestRect.w = m_Width;
    m_DestRect.h = m_Height;
}

void Animation::update(double elapsedSeconds) {
    m_CurrentTime += elapsedSeconds;

    if (m_CurrentTime > m_Duration) {
        m_CurrentTime -= m_Duration;
    }

    auto frameIndex = int(m_CurrentTime / m_Duration * m_Frames);

    m_SourceRect.y = (frameIndex * m_FrameHeight) + m_InitYSprite;
    m_Texture->setSourceRect(&m_SourceRect);
}

void Animation::render(bool isFlip) const {
    m_Texture->render(&m_DestRect, isFlip);
}

void Animation::release() {
    m_Texture->release();
    delete m_Texture;
}

int Animation::getWormWidth() const {
    return m_Width;
}

int Animation::getWormHeight() const {
    return m_Height;
}

void Animation::setPositions(float x, float y) {
    m_DestRect.x = x;
    m_DestRect.y = y;
}
