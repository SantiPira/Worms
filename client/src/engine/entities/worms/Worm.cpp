#include "engine/entities/worms/Worm.h"

Worm::Worm(SDL_Renderer *renderer, float posX, float posY) : m_Renderer(renderer), m_WormWidth(60), m_WormHeight(60),
    m_WormXPosition(posX), m_BlendMode({true, 128, 128, 192}) {
    m_DestWormRect = SDL_Rect{static_cast<int>(WorldScale::getPixelScale(posX)),
                              static_cast<int>(512 - WorldScale::getPixelScale(posY)), m_WormWidth, m_WormHeight};
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

void Worm::update(double elapsedSeconds, const GameUpdate& gameUpdate) {
    m_WormAnimation->update(elapsedSeconds);
    if (gameUpdate.action != WORM_NONE) {
        m_Dir = gameUpdate.action;
        float tempX = WorldScale::getPixelScale(gameUpdate.x_pos);
        float tempY = 512 - WorldScale::getPixelScale(gameUpdate.y_pos);
        if (tempX + m_WormWidth > 512) {
            m_DestWormRect.x = 512 - m_WormWidth;
        } else if (tempX < 0) {
            m_DestWormRect.x = 0;
        } else {
            m_DestWormRect.x = tempX;
        }
        if (tempY + m_WormHeight > 512) {
            m_DestWormRect.y = 512 - m_WormHeight;
        } else if (tempY < 0) {
            m_DestWormRect.y = 0;
        } else {
            m_DestWormRect.y = tempY;
        }
    }
}

void Worm::render() {
    bool isFlip = true;
    if (m_Dir == WORM_MOVE_LEFT) {
        isFlip = false;
    }
    m_WormAnimation->render(&m_DestWormRect, isFlip);
}
