#pragma once

#include "messages/sprites/SpritesEnum.h"

class SpriteAnimations {
protected:
    SpritesEnum m_CurrentSprite = SPRITE_WACCUSE_IDLE;
public:
    virtual ~SpriteAnimations() = default;
    virtual void update() = 0;
    virtual void reset() = 0;
    virtual bool hasFinished() = 0;
    virtual SpritesEnum getCurrentSprite() const = 0;
};