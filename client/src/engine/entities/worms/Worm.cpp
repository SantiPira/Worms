#include "engine/entities/worms/Worm.h"

Worm::Worm(SDL_Renderer *renderer, float posX, float posY, float width, float height)
        : m_Renderer(renderer), m_WormXPosition(posX),
          m_WormYPosition(posY), m_Widht(WorldScale::toPixel(width)), m_Height(WorldScale::toPixel(height)) {}

void Worm::init() {
        m_CurrentSprite = SpritesEnum::SPRITE_WACCUSE_IDLE;
        WaccuseIdle waccuseIdle;
        WaccuseWalk waccuseWalk;
        WaccuseJumping waccuseJumping;
        WaccuseDie waccuseDie;
        WaccuseGettingDamage waccuseGettingDamage;
        GraveSkin waccuseGrave;
        SettingAxe waSettingAxe;
        HasAxe waHasAxe;
        SavingAxe waSavingAxe;
        SettingBate waSettingBate;
        HasBate wHasBate;
        SavingBate wSavingBate;
        AttackAxe wAttackAxe;
        SettingBazooka wSettingBazooka;
        HasBazooka wHasBazooka;
        SavingBazooka wSavingBazooka;


    SDL_Rect destRect = {
                static_cast<int>(WorldScale::worldToPixelX(m_WormXPosition, m_Widht)),
                static_cast<int>(WorldScale::worldToPixelY(m_WormYPosition, m_Height)),
                static_cast<int>(m_Widht), static_cast<int>(m_Height)
        };


        m_SpritesMap.emplace(SpritesEnum::SPRITE_SETTING_BAZOOKA, getWaccuseAnimation(
            wSettingBazooka.spritePath,
            wSettingBazooka.blendMode,
            wSettingBazooka.frames,
            wSettingBazooka.distanceBetweenFrames,
            wSettingBazooka.frameWidth,
            wSettingBazooka.frameHeight,
            wSettingBazooka.duration,
            wSettingBazooka.srcRect,
            wSettingBazooka.initYSprite,
            destRect,
            wSettingBazooka.deltaPosX,
            wSettingBazooka.deltaPosY));

        m_SpritesMap.emplace(SpritesEnum::SPRITE_HAS_BAZOOKA, getWaccuseAnimation(
            wHasBazooka.spritePath,
            wHasBazooka.blendMode,
            wHasBazooka.frames,
            wHasBazooka.distanceBetweenFrames,
            wHasBazooka.frameWidth,
            wHasBazooka.frameHeight,
            wHasBazooka.duration,
            wHasBazooka.srcRect,
            wHasBazooka.initYSprite,
            destRect,
            wHasBazooka.deltaPosX,
            wHasBazooka.deltaPosY));

        m_SpritesMap.emplace(SpritesEnum::SPRITE_SAVING_BAZOOKA, getWaccuseAnimation(
            wSavingBazooka.spritePath,
            wSavingBazooka.blendMode,
            wSavingBazooka.frames,
            wSavingBazooka.distanceBetweenFrames,
            wSavingBazooka.frameWidth,
            wSavingBazooka.frameHeight,
            wSavingBazooka.duration,
            wSavingBazooka.srcRect,
            wSavingBazooka.initYSprite,
            destRect,
            wSavingBazooka.deltaPosX,
            wSavingBazooka.deltaPosY));


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
        m_SpritesMap.emplace(SpritesEnum::SPRITE_SETTING_AXE, getWaccuseAnimation(
                waSettingAxe.spritePath,
                waSettingAxe.blendMode,
                waSettingAxe.frames,
                waSettingAxe.distanceBetweenFrames,
                waSettingAxe.frameWidth,
                waSettingAxe.frameHeight,
                waSettingAxe.duration,
                waSettingAxe.srcRect,
                waSettingAxe.initYSprite,
                destRect,
                waSettingAxe.deltaPosX,
                waSettingAxe.deltaPosY));
    m_SpritesMap.emplace(SpritesEnum::SPRITE_HAS_AXE, getWaccuseAnimation(
            waHasAxe.spritePath,
            waHasAxe.blendMode,
            waHasAxe.frames,
            waHasAxe.distanceBetweenFrames,
            waHasAxe.frameWidth,
            waHasAxe.frameHeight,
            waHasAxe.duration,
            waHasAxe.srcRect,
            waHasAxe.initYSprite,
            destRect,
            waHasAxe.deltaPosX,
            waHasAxe.deltaPosY));
    m_SpritesMap.emplace(SpritesEnum::SPRITE_SAVING_AXE, getWaccuseAnimation(
            waSavingAxe.spritePath,
            waSavingAxe.blendMode,
            waSavingAxe.frames,
            waSavingAxe.distanceBetweenFrames,
            waSavingAxe.frameWidth,
            waSavingAxe.frameHeight,
            waSavingAxe.duration,
            waSavingAxe.srcRect,
            waSavingAxe.initYSprite,
            destRect,
            waSavingAxe.deltaPosX,
            waSavingAxe.deltaPosY));
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

    m_SpritesMap.emplace(SpritesEnum::SPRITE_SETTING_BATE, getWaccuseAnimation(
            waSettingBate.spritePath,
            waSettingBate.blendMode,
            waSettingBate.frames,
            waSettingBate.distanceBetweenFrames,
            waSettingBate.frameWidth,
            waSettingBate.frameHeight,
            waSettingBate.duration,
            waSettingBate.srcRect,
            waSettingBate.initYSprite,
            destRect,
            waSettingBate.deltaPosX,
            waSettingBate.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_HAS_BATE, getWaccuseAnimation(
            wHasBate.spritePath,
            wHasBate.blendMode,
            wHasBate.frames,
            wHasBate.distanceBetweenFrames,
            wHasBate.frameWidth,
            wHasBate.frameHeight,
            wHasBate.duration,
            wHasBate.srcRect,
            wHasBate.initYSprite,
            destRect,
            wHasBate.deltaPosX,
            wHasBate.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_SAVING_BATE, getWaccuseAnimation(
            wSavingBate.spritePath,
            wSavingBate.blendMode,
            wSavingBate.frames,
            wSavingBate.distanceBetweenFrames,
            wSavingBate.frameWidth,
            wSavingBate.frameHeight,
            wSavingBate.duration,
            wSavingBate.srcRect,
            wSavingBate.initYSprite,
            destRect,
            wSavingBate.deltaPosX,
            wSavingBate.deltaPosY));

    m_SpritesMap.emplace(SpritesEnum::SPRITE_ATTACK_AXE, getWaccuseAnimation(
            wAttackAxe.spritePath,
            wAttackAxe.blendMode,
            wAttackAxe.frames,
            wAttackAxe.distanceBetweenFrames,
            wAttackAxe.frameWidth,
            wAttackAxe.frameHeight,
            wAttackAxe.duration,
            wAttackAxe.srcRect,
            wAttackAxe.initYSprite,
            destRect,
            wAttackAxe.deltaPosX,
            wAttackAxe.deltaPosY));

    for (auto& sprite : m_SpritesMap) {
        sprite.second->init();
    }
}

void Worm::update(double elapsedSeconds, const GameUpdate& gameUpdate) {
    m_CurrentSprite = gameUpdate.m_CurrentSprite;
    m_SpritesMap.at(m_CurrentSprite)->update(elapsedSeconds);

    if (gameUpdate.m_Movement != GameAction::INVALID_ACTION) {
        m_Dir = gameUpdate.m_Dir;
        Animation* anim = m_SpritesMap.at(m_CurrentSprite).get();
        float tempX = WorldScale::worldToPixelX(gameUpdate.x_pos, anim->getDeltaPosX());
        float tempY = WorldScale::worldToPixelY(gameUpdate.y_pos, anim->getDeltaPosY());
        anim->setDestRect({static_cast<int>(tempX), static_cast<int>(tempY), anim->getFrameWidth(),
                           anim->getFrameHeight()});
        m_WormXPosition = gameUpdate.x_pos;
        m_WormYPosition = gameUpdate.y_pos;
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

void Worm::update(double elapsedSeconds) {
    Animation* anim = m_SpritesMap.at(m_CurrentSprite).get();
    float tempX = WorldScale::worldToPixelX(m_WormXPosition, anim->getDeltaPosX());
    float tempY = WorldScale::worldToPixelY(m_WormYPosition, anim->getDeltaPosY());
    anim->setDestRect({static_cast<int>(tempX), static_cast<int>(tempY), anim->getFrameWidth(),
                       anim->getFrameHeight()});
    m_SpritesMap.at(m_CurrentSprite)->update(elapsedSeconds);
}


