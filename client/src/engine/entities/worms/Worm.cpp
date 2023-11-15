#include "engine/entities/worms/Worm.h"

Worm::Worm(SDL_Renderer *renderer, float posX, float posY) : m_Renderer(renderer), m_WormXPosition(posX),
    m_WormYPosition(posY), m_Widht(1.0f * 25.6f), m_Height(1.6f * 25.6f)  {}

void Worm::init() {
    //TODO: Enum for paths and sprites actions
    //TODO: Worms::WORM_WALKING_SPRITESHEET_PATH
    SDL_Rect srcRect = {19, 16, 24, 28};
    m_WormAnimation = new Animation(std::filesystem::current_path().concat(Worm_Sprite_Waccuse.c_str()).c_str(),
                                    m_Renderer, 36, 2, srcRect, 16, 60, 60, {true, 128, 128, 192},
                                    static_cast<int>(m_Widht), static_cast<int>(m_Height),
                                    WorldScale::worldToPixelX(m_WormXPosition, m_Widht),
                                    WorldScale::worldToPixelY(m_WormYPosition, m_Height));
    m_CurrentAnimation = m_WormAnimation;
    m_CurrentSprite = SpritesEnum::SPRITE_WALK;
//    auto* axeAnimation = new Animation(std::filesystem::current_path().concat(Worm_Sprite_Axe_Walk.c_str()).c_str(),
//                                            m_Renderer, 15, 4, 104, 104, {true, 192, 192, 128}, 104, 104,
//                                            m_WormXPosition, m_WormYPosition);
//    auto* axeAttackAnimation = new Animation(std::filesystem::current_path().concat(Worm_Sprite_Axe_Attack.c_str()).c_str(),
//                                       m_Renderer, 4, 2, 104, 104, {true, 192, 192, 128}, 104, 104, m_WormXPosition,
//                                       m_WormYPosition);
    m_SpritesMap.insert(std::make_pair(SpritesEnum::SPRITE_WALK, m_WormAnimation));
//    m_SpritesMap.insert(std::make_pair(SpritesEnum::SPRITE_AXE_WALK, axeAnimation));
//    m_SpritesMap.insert(std::make_pair(SpritesEnum::SPRITE_AXE_WALK, axeAttackAnimation));
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
            m_CurrentSprite = SpritesEnum::SPRITE_WALK;
        }
        if (weapon == Weapon::AXE) {
            m_CurrentAnimation = m_SpritesMap.at(SPRITE_AXE_WALK);
            m_CurrentSprite = SpritesEnum::SPRITE_AXE_WALK;
        }
        m_CurrentAnimation->update(elapsedSeconds);
        if (gameUpdate.m_Move != WORM_NONE) {
            if (m_CurrentSprite == SpritesEnum::SPRITE_WALK) {
                moveNormalWorm(gameUpdate);
            } else {
                m_WormXPosition = WorldScale::worldToPixelX(gameUpdate.x_pos, m_CurrentAnimation->getWormWidth());
                m_WormYPosition = WorldScale::worldToPixelY(gameUpdate.y_pos, m_CurrentAnimation->getWormHeight());
                m_CurrentAnimation->setPositions(m_WormXPosition, m_WormYPosition);
            }
        }
    }
}

void Worm::render() {
    bool isFlip = true;
    if (m_Dir == WORM_MOVE_LEFT) {
        isFlip = false;
    }
    m_CurrentAnimation->render(isFlip);
}

void Worm::moveNormalWorm(const GameUpdate& gameUpdate) {
    m_Dir = gameUpdate.m_Move;
    float tempX = WorldScale::worldToPixelX(gameUpdate.x_pos, m_CurrentAnimation->getWormWidth());
    float tempY = WorldScale::worldToPixelY(gameUpdate.y_pos, m_CurrentAnimation->getWormHeight());
//    int wormWidth = m_CurrentAnimation->getWormWidth();
//    int wormHeight = m_CurrentAnimation->getWormHeight();
//    if (tempX + wormWidth > 512) {
//        tempX = 512 - wormWidth;
//    } else if (tempX < 0) {
//        tempX = 0;
//    }
//    if (tempY + wormHeight > 512) {
//        tempY = 512 - wormHeight;
//    } else if (tempY < 0) {
//        tempY = 0;
//    }
    m_CurrentAnimation->setPositions(tempX, tempY);
}
