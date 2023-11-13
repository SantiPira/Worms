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
    m_CurrentAnimation = m_WormAnimation;
    auto* axeAnimation = new Animation(std::filesystem::current_path().concat(Worm_Sprite_Axe_Walk.c_str()).c_str(),
                                            m_Renderer, 15, 4, 104, 104, {true, 192, 192, 128});
    auto* axeAttackAnimation = new Animation(std::filesystem::current_path().concat(Worm_Sprite_Axe_Attack.c_str()).c_str(),
                                       m_Renderer, 4, 2, 104, 104, {true, 192, 192, 128});
    m_SpritesMap.insert(std::make_pair(SpritesEnum::SPRITE_WALK, m_WormAnimation));
    m_SpritesMap.insert(std::make_pair(SpritesEnum::SPRITE_AXE_WALK, axeAnimation));
    m_SpritesMap.insert(std::make_pair(SpritesEnum::SPRITE_AXE_WALK, axeAttackAnimation));
    for (auto& sprite : m_SpritesMap) {
        sprite.second->init();
    }
}

void Worm::release() {
    m_WormAnimation->release();
    delete m_WormAnimation;
}

void Worm::update(double elapsedSeconds, const GameUpdate& gameUpdate) {
    if (gameUpdate.m_Move == GameAction::WORM_NONE) {
        m_CurrentAnimation->update(elapsedSeconds);
    } else {
        Weapon weapon(gameUpdate.m_Weapon);
        if (weapon == Weapon::NO_WEAPON) {
            m_CurrentAnimation = m_SpritesMap.at(SPRITE_WALK);
        }
        if (weapon == Weapon::AXE) {
            m_CurrentAnimation = m_SpritesMap.at(SPRITE_AXE_WALK);
        }
        m_CurrentAnimation->update(elapsedSeconds);
        if (gameUpdate.m_Move != WORM_NONE) {
            m_Dir = gameUpdate.m_Move;
            float tempX = WorldScale::getPixelScale(gameUpdate.x_pos);
            float tempY = 512 - WorldScale::getPixelScale(gameUpdate.y_pos);
            int wormWidth = m_CurrentAnimation->getWormWidth();
            int wormHeight = m_CurrentAnimation->getWormHeight();
            if (tempX + wormWidth > 512) {
                m_DestWormRect.x = 512 - wormWidth;
            } else if (tempX < 0) {
                m_DestWormRect.x = 0;
            } else {
                m_DestWormRect.x = tempX;
            }
            if (tempY + wormHeight > 512) {
                m_DestWormRect.y = 512 - wormHeight;
            } else if (tempY < 0) {
                m_DestWormRect.y = 0;
            } else {
                m_DestWormRect.y = tempY;
            }
        }
    }
}

void Worm::render() {
    bool isFlip = true;
    if (m_Dir == WORM_MOVE_LEFT) {
        isFlip = false;
    }
    m_CurrentAnimation->render(&m_DestWormRect, isFlip);
}
