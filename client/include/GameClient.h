#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL2pp/SDL2pp.hh>
#include <iostream>
#include <filesystem>
#include "engine/entities/worms/Worm.h"
#include "ParseMapFromFile.h"
#include "engine/entities/grd/GrdLarge.h"
#include "engine/graphics/Texture.h"
#include "messages/server/GameUpdate.h"
#include <unordered_map>
#include <vector>
#include "../include/camara.h"

class GameClient {
 private:
    int m_IdPlayer;

    SDL_Window *_window;
    SDL_Renderer *_renderer;

    std::unordered_map<int, Worm*> m_Worms;
    std::vector<Grd> m_Grd;
    std::vector<GrdLarge*> m_GrdLarge;
    std::vector<Worm*> m_WormsDie;
    Texture* sky;
    Texture* water;

    SDL2pp::Mixer *mixer;
    SDL2pp::Chunk *chunk;
    Camara* camara;


 private:
    void InitSDL();

    void CreateWindowAndRender();

    void InitMixerAndChunk();

    void InitCamera();

 public:
    void Init(const std::vector<Grd>& vector, int idPlayer, std::vector<GameUpdate>& initInfo);

    void Update(double elapsedSeconds, const GameUpdate& gameUpdate);

    void Render();

    void Release();
};
