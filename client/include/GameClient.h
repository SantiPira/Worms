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

struct WormDie {
    int idPlayer;
    bool isDie;
    WormDie() : idPlayer(0), isDie(false) {}
};

class GameClient {
 private:
    int m_IdPlayer;

    SDL_Window *_window;
    SDL_Renderer *_renderer;

    std::unordered_map<int, Worm*> m_Worms;
    std::vector<Grd> m_Grd;
    std::vector<GrdLarge*> m_GrdLarge;
    Texture* sky;

    SDL2pp::Mixer *mixer;
    SDL2pp::Chunk *chunk;

 private:
    void InitSDL();

    void CreateWindowAndRender();

    void InitMixerAndChunk();

 public:
    void Init(const std::vector<Grd>& vector, int idPlayer, std::vector<GameUpdate>& initInfo);

    void Update(double elapsedSeconds, const GameUpdate& gameUpdate);

    void Render(const WormDie& wormDie);

    void Release();




};