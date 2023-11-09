#include "engine/graphics/Animation.h"

Animation::Animation(std::string path, SDL_Renderer *renderer, int frames, float duration, int frameHeight,
                     int frameWidth) : m_Texture(new Texture(std::move(path), renderer)), m_Frames(frames),
                     m_Duration(duration), m_CurrentTime(0.0f), m_SourceRect(), m_FrameHeight(frameHeight),
                     m_FrameWidth(frameWidth) {}

void Animation::init() {
    m_Texture->init();
    m_SourceRect.w = m_FrameWidth;
    m_SourceRect.h = m_FrameHeight;
}

void Animation::update(double elapsedSeconds) {
    m_CurrentTime += elapsedSeconds;

    if (m_CurrentTime > m_Duration) {
        m_CurrentTime -= m_Duration;
    }

    auto frameIndex = int(m_CurrentTime / m_Duration * 10);

    m_SourceRect.x = frameIndex * m_FrameWidth;
    m_Texture->setSourceRect(&m_SourceRect);
}

void Animation::render(const SDL_Rect *destRect) const {
    m_Texture->render(destRect);
}

void Animation::release() {
    m_Texture->release();
    delete m_Texture;
}