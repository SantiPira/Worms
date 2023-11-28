/*
#include "engine/entities/projectiles/projectile.h"

Projectile::Projectile(SDL_Renderer *renderer): 
        m_Renderer(renderer), m_ProjectileXPosition(0),
         m_ProjectileYPosition(0), m_Widht(0), m_Height(WorldScale::toPixel(0)) {}

void Projectile::init(){

    GreenGranade wGreenGranade;
    BazookaMissile wBazookaMissile;

    SDL_Rect destRect = {
                static_cast<int>(WorldScale::worldToPixelX(m_ProjectileXPosition, m_Widht)),
                static_cast<int>(WorldScale::worldToPixelY(m_ProjectileYPosition, m_Height)),
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

    m_SpritesMap.emplace(SpritesEnum::SPRITE_BAZOOKA_MISSILE, getWaccuseAnimation(
                wBazookaMissile.spritePath,
                wBazookaMissile.blendMode,
                wBazookaMissile.frames,
                wBazookaMissile.distanceBetweenFrames,
                wBazookaMissile.frameWidth,
                wBazookaMissile.frameHeight,
                wBazookaMissile.duration,
                wBazookaMissile.srcRect,
                wBazookaMissile.initYSprite,
                destRect,
                wBazookaMissile.deltaPosX,
                wBazookaMissile.deltaPosY));

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

     Animation* anim = m_SpritesMap.at(m_CurrentSprite).get();
    float tempX = WorldScale::worldToPixelX(m_WormXPosition, anim->getDeltaPosX());
    float tempY = WorldScale::worldToPixelY(m_WormYPosition, anim->getDeltaPosY());
    anim->setDestRect({static_cast<int>(tempX), static_cast<int>(tempY), anim->getFrameWidth(),
                       anim->getFrameHeight()});
    m_SpritesMap.at(m_CurrentSprite)->update(elapsedSeconds); 
}

void Projectile::render(){

 bool isFlip = true;
    if (m_Dir == Direction::LEFT) {
        isFlip = false;
    }

    m_SpritesMap.at(m_CurrentSprite)->render(isFlip);
}
*/