#include "engine/entities/worms/Worm.h"

Worm::Worm(SDL_Renderer *renderer, float posX, float posY, float width, float height)
        : m_Renderer(renderer), m_WormXPosition(posX),
          m_WormYPosition(posY), m_Widht(WorldScale::toPixel(width)), m_Height(WorldScale::toPixel(height)) {}

void Worm::init() {
        m_CurrentSprite = SpritesEnum::SPRITE_WALK;
        WaccuseWalk waccuseWalk;
        WaccuseAxe waccuseAxe;
        WaccuseJumping waccuseJumping;
        SDL_Rect destRect = {
                static_cast<int>(WorldScale::worldToPixelX(m_WormXPosition, m_Widht)),
                static_cast<int>(WorldScale::worldToPixelY(m_WormYPosition, m_Height)),
                static_cast<int>(m_Widht), static_cast<int>(m_Height)
        };
        m_SpritesMap.emplace(SpritesEnum::SPRITE_WALK, getWaccuseAnimation(waccuseWalk.spritePath,
                                                                           waccuseWalk.blendMode,
                                                                            waccuseWalk.frames,
                                                                            waccuseWalk.distanceBetweenFrames,
                                                                            waccuseWalk.frameWidth,
                                                                            waccuseWalk.frameHeight,
                                                                            waccuseWalk.duration,
                                                                            waccuseWalk.srcRect,
                                                                            waccuseWalk.initYSprite,
                                                                            destRect));
        m_SpritesMap.emplace(SpritesEnum::SPRITE_AXE_WALK, getWaccuseAnimation(waccuseAxe.spritePath,
                                                                               waccuseAxe.blendMode,
                                                                               waccuseAxe.frames,
                                                                               waccuseAxe.distanceBetweenFrames,
                                                                               waccuseAxe.frameWidth,
                                                                               waccuseAxe.frameHeight,
                                                                               waccuseAxe.duration,
                                                                               waccuseAxe.srcRect,
                                                                               waccuseAxe.initYSprite,
                                                                               destRect));
    m_SpritesMap.emplace(SpritesEnum::SPRITE_JUMPING, getWaccuseAnimation(waccuseJumping.spritePath,
                                                                           waccuseJumping.blendMode,
                                                                           waccuseJumping.frames,
                                                                           waccuseJumping.distanceBetweenFrames,
                                                                           waccuseJumping.frameWidth,
                                                                           waccuseJumping.frameHeight,
                                                                           waccuseJumping.duration,
                                                                           waccuseJumping.srcRect,
                                                                           waccuseJumping.initYSprite,
                                                                           destRect));
        for (auto& sprite : m_SpritesMap) {
            sprite.second->init();
        }
}

void Worm::update(double elapsedSeconds, const GameUpdate& gameUpdate) {
    m_Dir = gameUpdate.m_Dir;
    if (gameUpdate.m_Move == GameAction::WORM_NONE) {
        m_SpritesMap.at(m_CurrentSprite)->update(elapsedSeconds);
    } else {
        if (gameUpdate.m_Health < 100) {
            std::cout << "Worm " << gameUpdate.player_id << " has " << gameUpdate.m_Health << " health" << std::endl;
        }
        Weapon weapon(gameUpdate.m_Weapon);
        if (weapon == Weapon::NO_WEAPON) {
            if (gameUpdate.m_Move == GameAction::WORM_JUMP) {
                m_CurrentSprite = SpritesEnum::SPRITE_JUMPING;
            } else {
                m_CurrentSprite = SpritesEnum::SPRITE_WALK;
            }
        }
        if (weapon == Weapon::AXE) {
            m_CurrentSprite = SpritesEnum::SPRITE_AXE_WALK;
        }
        m_SpritesMap.at(m_CurrentSprite)->update(elapsedSeconds);
        if (gameUpdate.m_Move != WORM_NONE) {
            if (m_CurrentSprite == SpritesEnum::SPRITE_WALK || m_CurrentSprite == SpritesEnum::SPRITE_JUMPING) {
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
    if (m_Dir == Direction::LEFT) {
        isFlip = false;
    }
    m_SpritesMap.at(m_CurrentSprite)->render(isFlip);
}

std::unique_ptr<Animation> Worm::getWaccuseAnimation(const std::string& spritePath, BlendMode blendMode, int frames,
                                                     int distanceBetweenFrames,
                                                     int frameWidth, int frameHeight, float duration, SDL_Rect srcRect,
                                                     int initYSprite, SDL_Rect destRect) {
    return std::unique_ptr<Animation>(new Animation(spritePath,m_Renderer, blendMode, frames, distanceBetweenFrames,
                                                    frameWidth, frameHeight, duration, srcRect, initYSprite, destRect));
}


