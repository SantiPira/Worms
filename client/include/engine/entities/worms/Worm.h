#pragma once

#include <SDL_render.h>
#include <iostream>
#include "SpritesEnum.h"
#include "utils/WorldScale.h"
#include "engine/graphics/Animation.h"
#include "engine/entities/TexturePaths.h"
#include "Skins.h"
#include "engine/entities/effects/EffectSkins.h"
#include "messages/server/GameUpdate.h"
#include "messages/user_actions/ActionType.h"
#include "messages/user_actions/WeaponID.h"
#include <filesystem>
#include <unordered_map>
#include <vector>

class Worm {
 private:
    SDL_Renderer* m_Renderer;
    std::unordered_map<SpritesEnum, std::unique_ptr<Animation>> m_SpritesMap;

 public:
    float m_WormXPosition;
    float m_WormYPosition;
 private:
    SpritesEnum m_CurrentSprite;
 public:
    float m_Widht;
    float m_Height;
    
 private:
    Direction m_Dir;
    std::vector<SDL_Rect > m_DieRects;

private:
    std::unique_ptr<Animation> getWaccuseAnimation(const std::string& spritePath, BlendMode blendMode, int frames,
                                                   int distanceBetweenFrames,
                                                   int frameWidth, int frameHeight, float duration, SDL_Rect srcRect,
                                                   int initYSprite, SDL_Rect destRect, float deltaPosX, float deltaPosY);

 public:
    Worm(SDL_Renderer *renderer, float posX, float posY, float d, float d1);

    void init();
    void update(double elapsedSeconds, const GameUpdate& gameUpdate);
    void render();

    ~Worm() = default;

    void renderDie();

    SpritesEnum chooseSprite(const GameUpdate &gameUpdate) const;
};