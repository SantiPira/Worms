#include "engine/entities/projectiles/projectile.h"
/*
Projectile::Projectile(SDL_Renderer *renderer, float posX, float posY, float width, float height): 
        m_Renderer(renderer), m_ProjectileXPosition(posX),
         m_ProjectileYPosition(posY), m_Widht(WorldScale::toPixel(width)), m_Height(WorldScale::toPixel(height)) {}

void Projectile::init(){

    GreenGranade wGreenGranade;

    SDL_Rect destRect = {
                static_cast<int>(WorldScale::worldToPixelX(m_WormXPosition, m_Widht)),
                static_cast<int>(WorldScale::worldToPixelY(m_WormYPosition, m_Height)),
                static_cast<int>(m_Widht), static_cast<int>(m_Height)
    };

    m_SpritesMap.emplace(SpritesEnum::SPRITE_GREEN_GRENADE, getWaccuseAnimation(
                wGreenGranade.spritePath,
                wGreenGranade.blendMode,
                wGreenGranade.frames,
                wGreenGranade.distanceBetweenFrames,
                wGreenGranade.frameWidth,
                wGreenGranade.frameHeight,
                wGreenGranade.duration,
                wGreenGranade.srcRect,
                wGreenGranade.initYSprite,
                destRect,
                wGreenGranade.deltaPosX,
                wGreenGranade.deltaPosY));

}

void Projectile::update(double elapsedSeconds, const GameUpdate& gameUpdate){
    m_CurrentSprite = gameUpdate.m_CurrentSprite;
    m_SpritesMap.at(m_CurrentSprite)->update(elapsedSeconds);

    if (gameUpdate.m_Movement != GameAction::INVALID_ACTION) {
        m_Dir = gameUpdate.m_Dir;
        Animation* anim = m_SpritesMap.at(m_CurrentSprite).get();
        float tempX = WorldScale::worldToPixelX(gameUpdate.x_pos, anim->getDeltaPosX());
        float tempY = WorldScale::worldToPixelY(gameUpdate.y_pos, anim->getDeltaPosY());
        anim->setDestRect({static_cast<int>(tempX), static_cast<int>(tempY), anim->getFrameWidth(),
                           anim->getFrameHeight()});
        m_ProjectileXPosition = gameUpdate.x_pos;
        m_ProjectileYPosition = gameUpdate.y_pos;
    }

}

void Projectile::update(double elapsedSeconds){

    bool isFlip = true;
    if (m_Dir == Direction::LEFT) {
        isFlip = false;
    }

    m_SpritesMap.at(m_CurrentSprite)->render(isFlip);
}

void Projectile::render(){

}
*/