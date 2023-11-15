#pragma once

#include <SDL_render.h>
#include "SpritesEnum.h"
#include "utils/WorldScale.h"
#include "engine/graphics/Animation.h"
#include "engine/entities/TexturePaths.h"
#include "messages/server/GameUpdate.h"
#include "messages/user_actions/Weapon.h"
#include <filesystem>
#include <unordered_map>

class Worm {
private:
    SDL_Renderer* m_Renderer;
    Animation* m_WormAnimation{};
    std::unordered_map<SpritesEnum, Animation*> m_SpritesMap;
    SDL_Rect m_DestWormRect{};
    int m_WormWidth{};
    int m_WormHeight{};
    float m_WormXPosition;
    float m_WormYPosition;
    BlendMode m_BlendMode{};
    SpritesEnum m_CurrentSprite;
    float m_Widht;
    float m_Height;
    // Widht y Height corresponden a las dimensiones que tiene el gusano en el World
    // Se podria enviar del servidor al cliente al momento de iniciar/crear el gusano.

public:
    Worm(SDL_Renderer* renderer, float posX, float posY);

    void init();
    void release();
    void update(double elapsedSeconds, const GameUpdate& gameUpdate);
    void render();

    GameAction m_Dir;
    Animation* m_CurrentAnimation{};

    void moveNormalWorm(const GameUpdate& gameUpdate);
};