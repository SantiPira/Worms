#include "engine/entities/worms/Worm.h"

Worm::Worm(SDL_Renderer *renderer, float posX, float posY, float width, float height)
        : m_Renderer(renderer), m_WormXPosition(posX),
          m_WormYPosition(posY), m_Widht(WorldScale::toPixel(width)), m_Height(WorldScale::toPixel(height)) {}

void Worm::init() {
        m_CurrentSprite = SpritesEnum::SPRITE_WALK;
        m_SpritesMap.emplace(SpritesEnum::SPRITE_WALK, getWaccuseAnimation());
        m_SpritesMap.emplace(SpritesEnum::SPRITE_AXE_WALK, getWaccuseAxeAnimation());
        for (auto& sprite : m_SpritesMap) {
            sprite.second->init();
        }
}

void Worm::update(double elapsedSeconds, const GameUpdate& gameUpdate) {
    if (gameUpdate.m_Move == GameAction::WORM_NONE) {
        //m_CurrentAnimation->update(elapsedSeconds);
        m_SpritesMap.at(m_CurrentSprite)->update(elapsedSeconds);
    } else {
        Weapon weapon(gameUpdate.m_Weapon);
        if (weapon == Weapon::NO_WEAPON) {
            m_CurrentSprite = SpritesEnum::SPRITE_WALK;
            //m_CurrentAnimation = m_SpritesMap.at(m_CurrentSprite);
        }
        if (weapon == Weapon::AXE) {
            //m_CurrentAnimation = m_SpritesMap.at(SPRITE_AXE_WALK);
            m_CurrentSprite = SpritesEnum::SPRITE_AXE_WALK;
        }
        m_SpritesMap.at(m_CurrentSprite)->update(elapsedSeconds);
        if (gameUpdate.m_Move != WORM_NONE) {
            if (m_CurrentSprite == SpritesEnum::SPRITE_WALK) {
                m_Dir = gameUpdate.m_Move;
                float tempX = WorldScale::worldToPixelX(gameUpdate.x_pos, WorldScale::toPixel(gameUpdate.width));
                float tempY = WorldScale::worldToPixelY(gameUpdate.y_pos, WorldScale::toPixel(gameUpdate.height));
                m_SpritesMap.at(m_CurrentSprite)->setPositions(tempX, tempY);
            } else {
                float tempX = WorldScale::worldToPixelX(gameUpdate.x_pos, 47.0f);
                float tempY = WorldScale::worldToPixelY(gameUpdate.y_pos, 51.0f);
                m_SpritesMap.at(m_CurrentSprite)->setDestRect({static_cast<int>(tempX), static_cast<int>(tempY), 47, 47});
            }
        }
    }
}

void Worm::render() {
    bool isFlip = true;
    if (m_Dir == WORM_MOVE_LEFT) {
        isFlip = false;
    }
    m_SpritesMap.at(m_CurrentSprite)->render(isFlip);
}

std::unique_ptr<Animation> Worm::getWaccuseAnimation() {
    return std::unique_ptr<Animation>(
            new Animation(std::filesystem::current_path().concat(Worm_Sprite_Waccuse.c_str()).c_str(),
                          m_Renderer, {true, 128, 128, 192}, 36, 60, 22, 26, 2, {20, 17, 22, 26}, 17,
                          {
                            static_cast<int>(WorldScale::worldToPixelX(m_WormXPosition, m_Widht)),
                            static_cast<int>(WorldScale::worldToPixelY(m_WormYPosition, m_Height)),
                            static_cast<int>(m_Widht), static_cast<int>(m_Height)
                          }));
}

std::unique_ptr<Animation> Worm::getWaccuseAxeAnimation() {
    return std::unique_ptr<Animation>(
            new Animation(std::filesystem::current_path().concat(Worm_Sprite_Axe_Walk.c_str()).c_str(),
                          m_Renderer, {true, 192, 192, 128}, 15, 104, 41, 39, 2, {39, 26, 41, 39}, 26,
                          {
                            static_cast<int>(WorldScale::worldToPixelX(m_WormXPosition, m_Widht)),
                            static_cast<int>(WorldScale::worldToPixelY(m_WormYPosition, m_Height)),
                            static_cast<int>(m_Widht), static_cast<int>(m_Height)
                          }
                          ));
}

