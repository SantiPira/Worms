#include "engine/graphics/Animation.h"

Animation::Animation(std::string path, SDL_Renderer *renderer, int frames, float duration, int frameHeight,
                     int frameWidth, BlendMode blendMode) :
                     m_Texture(new Texture(std::move(path), renderer, std::move(blendMode))),
                     m_Frames(frames), m_Duration(duration), m_CurrentTime(0.0f), m_SourceRect(),
                     m_FrameHeight(frameHeight), m_FrameWidth(frameWidth) {}

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

    auto frameIndex = int(m_CurrentTime / m_Duration * m_Frames);

    m_SourceRect.y = frameIndex * m_FrameWidth;
    m_Texture->setSourceRect(&m_SourceRect);
}

void Animation::render(const SDL_Rect *destRect, bool isFlip) const {
    m_Texture->render(destRect, isFlip);
}

void Animation::release() {
    m_Texture->release();
    delete m_Texture;
}