#include "engine/entities/worms/Worm.h"

Worm::Worm(SDL_Renderer *renderer, int posX, int posY) : m_Renderer(renderer),
    m_DestWormRect(SDL_Rect{posX, posY, 60, 60}), m_WormXPosition(posX), m_BlendMode({true, 128, 128, 192}) {}

void Worm::init() {
    //TODO: Enum for paths and sprites actions
    //TODO: Worms::WORM_WALKING_SPRITESHEET_PATH
    m_WormAnimation = new Animation(std::filesystem::current_path().concat(Worm_Sprite_Waccuse.c_str()).c_str(),
                                    m_Renderer, 36, 1, 60, 60, m_BlendMode);
    m_WormAnimation->init();
}

void Worm::release() {
    m_WormAnimation->release();
    delete m_WormAnimation;
}

void Worm::update(double elapsedSeconds) {
    m_WormAnimation->update(elapsedSeconds);
}

void Worm::render() {
    m_WormAnimation->render(&m_DestWormRect, true);
}
