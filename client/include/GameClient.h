#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <filesystem>
#include "engine/entities/worms/Worm.h"
#include "ParseMapFromFile.h"
#include "engine/entities/grd/GrdLarge.h"
#include "messages/server/GameUpdate.h"
#include <unordered_map>
#include <vector>

class GameClient {
public:
    void Init(const std::vector<Grd>& vector, int idPlayer, std::vector<GameUpdate>& initInfo);

    void HandleEvents();

    void Update(double elapsedSeconds, const GameUpdate& gameUpdate);

    void Render();

    void Release();

    bool IsRunning();

private:
    void InitSDL();

    void CreateWindowAndRender();

private:
    bool _isRunning;
    int m_IdPlayer;

    SDL_Window *_window;
    SDL_Renderer *_renderer;

    std::unordered_map<int, Worm*> m_Worms;
    std::vector<Grd> m_Grd;
    std::vector<GrdLarge*> m_GrdLarge;
};