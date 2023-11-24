#include "engine/entities/worms/Worm.h"



SDL_Rect& Worm::getWormRect(){
    return (m_SpritesMap.at(this->m_CurrentSprite))->getDestRect();
}


Worm::Worm(SDL_Renderer *renderer, float posX, float posY, float width, float height)
        : m_Renderer(renderer), m_WormXPosition(posX),
          m_WormYPosition(posY), m_Widht(WorldScale::toPixel(width)), m_Height(WorldScale::toPixel(height)) {}

void Worm::init() {
        m_CurrentSprite = SpritesEnum::SPRITE_WACCUSE_IDLE;
        
        WaccuseIdle waccuseIdle;
        WaccuseWalk waccuseWalk;
        WaccuseAxe waccuseAxe;
        WaccuseJumping waccuseJumping;
        WaccuseDie waccuseDie;
        WaccuseGettingDamage waccuseGettingDamage;
        GraveSkin waccuseGrave;
        WaccuseSetBate waccuseSetBate;
        WaccuseSetBazooka waccuseSetBazooka;
        WaccuseSetGreenBomb waccuseSetGreenBomb;
        
        SDL_Rect destRect = {
                static_cast<int>(WorldScale::worldToPixelX(m_WormXPosition, m_Widht)),
                static_cast<int>(WorldScale::worldToPixelY(m_WormYPosition, m_Height)),
                static_cast<int>(m_Widht), static_cast<int>(m_Height)
        };

        std::vector<WaccuseConfigBase*> waccuseConfigBaseVector;

        waccuseConfigBaseVector.push_back(&waccuseWalk);
        waccuseConfigBaseVector.push_back(&waccuseAxe);
        waccuseConfigBaseVector.push_back(&waccuseJumping);
        waccuseConfigBaseVector.push_back(&waccuseGettingDamage);
        waccuseConfigBaseVector.push_back(&waccuseDie);
        waccuseConfigBaseVector.push_back(&waccuseGrave);
        waccuseConfigBaseVector.push_back(&waccuseIdle);
        waccuseConfigBaseVector.push_back(&waccuseSetBate);
        waccuseConfigBaseVector.push_back(&waccuseSetBazooka);
        waccuseConfigBaseVector.push_back(&waccuseSetGreenBomb);

        std::cout<<"waccuseConfigBaseVector.size() "<<waccuseConfigBaseVector.size()<<std::endl;

        for (size_t i = 0; i < waccuseConfigBaseVector.size(); i++) {
            WaccuseConfigBase* waccuse = waccuseConfigBaseVector[i];
            m_SpritesMap.emplace(static_cast<SpritesEnum>(i), getWaccuseAnimation(
                waccuse->spritePath,
                waccuse->blendMode,
                waccuse->frames,
                waccuse->distanceBetweenFrames,
                waccuse->frameWidth,
                waccuse->frameHeight,
                waccuse->duration,
                waccuse->srcRect,
                waccuse->initYSprite,
                destRect,
                waccuse->deltaPosX,
                waccuse->deltaPosY
            ));

        }

        std::cout<<"salio del for"<<std::endl;
        /*
        
        m_SpritesMap.emplace(SpritesEnum::SPRITE_WACCUSE_IDLE, getWaccuseAnimation(
                waccuseIdle.spritePath,
                waccuseIdle.blendMode,
                waccuseIdle.frames,
                waccuseIdle.distanceBetweenFrames,
                waccuseIdle.frameWidth,
                waccuseIdle.frameHeight,
                waccuseIdle.duration,
                waccuseIdle.srcRect,
                waccuseIdle.initYSprite,
                destRect,
                waccuseIdle.deltaPosX,
                waccuseIdle.deltaPosY));
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
                waccuseAxe.distanceBetweenFrames,S
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

    m_SpritesMap.emplace(SpritesEnum::SPRITE_WACCUSE_SET_BATE, getWaccuseAnimation(
            waccuseSetBate.spritePath,
            waccuseSetBate.blendMode,
            waccuseSetBate.frames,
            waccuseSetBate.distanceBetweenFrames,
            waccuseSetBate.frameWidth,
            waccuseSetBate.frameHeight,
            waccuseSetBate.duration,
            waccuseSetBate.srcRect,
            waccuseSetBate.initYSprite,
            destRect,
            waccuseSetBate.deltaPosX,
            waccuseSetBate.deltaPosY));

    //bazooka
    m_SpritesMap.emplace(SpritesEnum::SPRITE_WACCUSE_SET_BAZOOKA, getWaccuseAnimation(
            waccuseSetBazooka.spritePath,
            waccuseSetBazooka.blendMode,
            waccuseSetBazooka.frames,
            waccuseSetBazooka.distanceBetweenFrames,
            waccuseSetBazooka.frameWidth,
            waccuseSetBazooka.frameHeight,
            waccuseSetBazooka.duration,
            waccuseSetBazooka.srcRect,
            waccuseSetBazooka.initYSprite,
            destRect,
            waccuseSetBazooka.deltaPosX,
            waccuseSetBazooka.deltaPosY));
    
    m_SpritesMap.emplace(SpritesEnum::SPRITE_WACCUSE_SET_GREENBOMB, getWaccuseAnimation(
            waccuseSetGreenBomb.spritePath,
            waccuseSetGreenBomb.blendMode,
            waccuseSetGreenBomb.frames,
            waccuseSetGreenBomb.distanceBetweenFrames,
            waccuseSetGreenBomb.frameWidth,
            waccuseSetGreenBomb.frameHeight,
            waccuseSetGreenBomb.duration,
            waccuseSetGreenBomb.srcRect,
            waccuseSetGreenBomb.initYSprite,
            destRect,
            waccuseSetGreenBomb.deltaPosX,
            waccuseSetGreenBomb.deltaPosY));
    
        */

    

    for (auto& sprite : m_SpritesMap) {
        std::cout<<"cantidad de sprites "<<m_SpritesMap.size()<<std::endl;
        sprite.second->init();
    }

    std::cout<<"salio del init"<<std::endl;
}

void Worm::update(double elapsedSeconds, const GameUpdate& gameUpdate) {
    m_Dir = gameUpdate.m_Dir;
    m_CurrentSprite = chooseSprite(gameUpdate);

    m_SpritesMap.at(m_CurrentSprite)->update(elapsedSeconds);

    if (gameUpdate.m_Movement != INVALID_ACTION) {
        Animation* anim = m_SpritesMap.at(m_CurrentSprite).get();
        float tempX = WorldScale::worldToPixelX(gameUpdate.x_pos, anim->getDeltaPosX());
        float tempY = WorldScale::worldToPixelY(gameUpdate.y_pos, anim->getDeltaPosY());
        anim->setDestRect({static_cast<int>(tempX), static_cast<int>(tempY), anim->getFrameWidth(),
                           anim->getFrameHeight()});
        m_WormXPosition = tempX;
        m_WormYPosition = tempY;
    }
}

SpritesEnum Worm::chooseSprite(const GameUpdate& gameUpdate) const {
    if (gameUpdate.m_Movement == GameAction::INVALID_ACTION) {
        return m_CurrentSprite;
    } else if (gameUpdate.m_SelfCondition == GameAction::WORM_ATTACKED) {
        return SpritesEnum::SPRITE_WACCUSE_GETTING_DAMAGE;
    } else if (gameUpdate.m_SelfCondition == GameAction::WORM_DIE) {
        return SpritesEnum::SPRITE_WACCUSE_DIE;
    } else if (gameUpdate.m_SelfCondition == GameAction::WORM_GRAVE) {
        return SpritesEnum::SPRITE_WACCUSE_GRAVE;
    } else if (gameUpdate.m_Movement == GameAction::WORM_JUMP) {
        return SpritesEnum::SPRITE_JUMPING;
    } else if (gameUpdate.m_Weapon == WeaponID::AXE) {
        return SpritesEnum::SPRITE_AXE_WALK;
    } else if (gameUpdate.m_Weapon == WeaponID::BATE) {
        return SpritesEnum::SPRITE_WACCUSE_SET_BATE;
    } else if (gameUpdate.m_Movement == GameAction::WORM_MOVE_RIGHT ||
               gameUpdate.m_Movement == GameAction::WORM_MOVE_LEFT) {
        return SpritesEnum::SPRITE_WALK;
    }else if (gameUpdate.m_Weapon == WeaponID::BAZOOKA) {
        return SpritesEnum::SPRITE_WACCUSE_SET_BAZOOKA;
    }else if (gameUpdate.m_Weapon == WeaponID::GREENBOMB) {
        return SpritesEnum::SPRITE_WACCUSE_SET_GREENBOMB;
    }else {
        return SpritesEnum::SPRITE_WACCUSE_IDLE;
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


