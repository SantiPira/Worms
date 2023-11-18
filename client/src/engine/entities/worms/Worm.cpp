#include "engine/entities/worms/Worm.h"



SDL_Rect& Worm::getWormRect(){
    return (m_SpritesMap.at(this->m_CurrentSprite))->getDestRect();
}


Worm::Worm(SDL_Renderer *renderer, float posX, float posY, float width, float height)
        : m_Renderer(renderer), m_WormXPosition(posX),
          m_WormYPosition(posY), m_Widht(WorldScale::toPixel(width)), m_Height(WorldScale::toPixel(height)) {}

void Worm::init() {
        m_CurrentSprite = SpritesEnum::SPRITE_WALK;
        WaccuseWalk waccuseWalk;
        WaccuseAxe waccuseAxe;
        WaccuseJumping waccuseJumping;
        WaccuseDie waccuseDie;
        WaccuseGettingDamage waccuseGettingDamage;
        GraveSkin waccuseGrave;
        SDL_Rect destRect = {
                static_cast<int>(WorldScale::worldToPixelX(m_WormXPosition, m_Widht)),
                static_cast<int>(WorldScale::worldToPixelY(m_WormYPosition, m_Height)),
                static_cast<int>(m_Widht), static_cast<int>(m_Height)
        };
        m_SpritesMap.emplace(SpritesEnum::SPRITE_WALK, getWaccuseAnimation(
                waccuseWalk.spritePath,
                waccuseWalk.blendMode,
                waccuseWalk.frames,
                waccuseWalk.distanceBetweenFrames,
                waccuseWalk.frameWidth,
                waccuseWalk.frameHeight,
                waccuseWalk.duration,
                waccuseWalk.srcRect,
                waccuseWalk.initYSprite,
                destRect,
                waccuseWalk.deltaPosX,
                waccuseWalk.deltaPosY));
        m_SpritesMap.emplace(SpritesEnum::SPRITE_AXE_WALK, getWaccuseAnimation(
                waccuseAxe.spritePath,
                waccuseAxe.blendMode,
                waccuseAxe.frames,
                waccuseAxe.distanceBetweenFrames,
                waccuseAxe.frameWidth,
                waccuseAxe.frameHeight,
                waccuseAxe.duration,
                waccuseAxe.srcRect,
                waccuseAxe.initYSprite,
                destRect,
                waccuseAxe.deltaPosX,
                waccuseAxe.deltaPosY));
    m_SpritesMap.emplace(SpritesEnum::SPRITE_JUMPING, getWaccuseAnimation(
            waccuseJumping.spritePath,
            waccuseJumping.blendMode,
            waccuseJumping.frames,
            waccuseJumping.distanceBetweenFrames,
            waccuseJumping.frameWidth,
            waccuseJumping.frameHeight,
            waccuseJumping.duration,
            waccuseJumping.srcRect,
            waccuseJumping.initYSprite,
            destRect,
            waccuseJumping.deltaPosX,
            waccuseJumping.deltaPosY));
    m_SpritesMap.emplace(SpritesEnum::SPRITE_WACCUSE_DIE, getWaccuseAnimation(
            waccuseDie.spritePath,
            waccuseDie.blendMode,
            waccuseDie.frames,
            waccuseDie.distanceBetweenFrames,
            waccuseDie.frameWidth,
            waccuseDie.frameHeight,
            waccuseDie.duration,
            waccuseDie.srcRect,
            waccuseDie.initYSprite,
            destRect,
            waccuseDie.deltaPosX,
            waccuseDie.deltaPosY));
    m_SpritesMap.emplace(SpritesEnum::SPRITE_WACCUSE_GETTING_DAMAGE, getWaccuseAnimation(
            waccuseGettingDamage.spritePath,
            waccuseGettingDamage.blendMode,
            waccuseGettingDamage.frames,
            waccuseGettingDamage.distanceBetweenFrames,
            waccuseGettingDamage.frameWidth,
            waccuseGettingDamage.frameHeight,
            waccuseGettingDamage.duration,
            waccuseGettingDamage.srcRect,
            waccuseGettingDamage.initYSprite,
            destRect,
            waccuseGettingDamage.deltaPosX,
            waccuseGettingDamage.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_WACCUSE_GRAVE, getWaccuseAnimation(
            waccuseGrave.spritePath,
            waccuseGrave.blendMode,
            waccuseGrave.frames,
            waccuseGrave.distanceBetweenFrames,
            waccuseGrave.frameWidth,
            waccuseGrave.frameHeight,
            waccuseGrave.duration,
            waccuseGrave.srcRect,
            waccuseGrave.initYSprite,
            destRect,
            waccuseGrave.deltaPosX,
            waccuseGrave.deltaPosY));

    for (auto& sprite : m_SpritesMap) {
        sprite.second->init();
    }
}

void Worm::update(double elapsedSeconds, const GameUpdate& gameUpdate) {
    //TODO: Cuando setea un sprite en m_CurrentSprite ya no deberia setear ninguno mas (por esta accion en particular)
    m_Dir = gameUpdate.m_Dir;
    WeaponID weapon(gameUpdate.m_Weapon);
    if (gameUpdate.m_Move == GameAction::WORM_NONE) {
        m_SpritesMap.at(m_CurrentSprite)->update(elapsedSeconds);
    } else {
        //TODO: Aca habria que hacer un Factory de Sprites para no estar asignando a manopla cada Sprite por cada accion distinta
        if (gameUpdate.m_SelfCondition == GameAction::WORM_ATTACKED) {
            m_CurrentSprite = SpritesEnum::SPRITE_WACCUSE_GETTING_DAMAGE;
        } else if (gameUpdate.m_SelfCondition == GameAction::WORM_DIE) {
            m_CurrentSprite = SpritesEnum::SPRITE_WACCUSE_DIE;
        } else if (gameUpdate.m_SelfCondition == GameAction::WORM_GRAVE) {
            m_CurrentSprite = SpritesEnum::SPRITE_WACCUSE_GRAVE;
        } else if (weapon == WeaponID::NO_WEAPON) {
            if (gameUpdate.m_Move == GameAction::WORM_JUMP) {
                m_CurrentSprite = SpritesEnum::SPRITE_JUMPING;
            } else {
                m_CurrentSprite = SpritesEnum::SPRITE_WALK;
            }
        } else if (weapon == WeaponID::AXE) {
            m_CurrentSprite = SpritesEnum::SPRITE_AXE_WALK;
        }
        m_SpritesMap.at(m_CurrentSprite)->update(elapsedSeconds);

        if (gameUpdate.m_Move != WORM_NONE) {
            Animation* anim = m_SpritesMap.at(m_CurrentSprite).get();
            float tempX = WorldScale::worldToPixelX(gameUpdate.x_pos, anim->getDeltaPosX());
            float tempY = WorldScale::worldToPixelY(gameUpdate.y_pos, anim->getDeltaPosY());
            anim->setDestRect({static_cast<int>(tempX), static_cast<int>(tempY), anim->getFrameWidth(),
                               anim->getFrameHeight()});
            m_WormXPosition = tempX;
            m_WormYPosition = tempY;
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
                                                     int initYSprite, SDL_Rect destRect, float deltaPosX, float deltaPosY) {
    return std::unique_ptr<Animation>(new Animation(spritePath,m_Renderer, blendMode, frames, distanceBetweenFrames,
                                                    frameWidth, frameHeight, duration, srcRect, initYSprite, destRect,
                                                    deltaPosX, deltaPosY));
}

void Worm::renderDie() {
    /*BlobSkin blobSkin;
    Animation* explotion = new Animation(blobSkin.spritePath,
                                         m_Renderer,
                                         blobSkin.blendMode,
                                         blobSkin.frames,
                                         blobSkin.distanceBetweenFrames,
                                         blobSkin.frameWidth,
                                         blobSkin.frameHeight,
                                         blobSkin.duration,
                                         blobSkin.srcRect,
                                         blobSkin.initYSprite,
                                         {static_cast<int>(m_WormXPosition), static_cast<int>(m_WormYPosition),
                                          blobSkin.frameWidth, blobSkin.frameHeight},
                                         blobSkin.deltaPosX,
                                         blobSkin.deltaPosY);
    explotion->init();
    explotion.*/

}
