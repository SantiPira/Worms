#pragma once

#include "engine/entities/worms/Worm.h"
#include "ParseMapFromFile.h"
#include "engine/entities/grd/GrdLarge.h"
#include "../../common_libs/include/ProtectedQueue.h"
#include "../../common_libs/include/messages/server/GameUpdate.h"

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <filesystem>
#include <vector>

class GameClient {
public:

    GameClient(ProtectedQueue<GameUpdate>& updaptesQueue);

    void Init(const std::vector<Grd> vector);

    void HandleEvents();

    void Update(double elapsedSeconds);

    void Render();

    void Release();

    bool IsRunning();

private:

    void getGameUpdates();

    void InitSDL();

    void CreateWindowAndRender();

private:
    ProtectedQueue<GameUpdate>& gameUpdates;
    bool _isRunning;

    SDL_Window *_window;
    SDL_Renderer *_renderer;

    std::vector<Worm*> m_Worms;
    std::vector<Grd> m_Grd;
    std::vector<GrdLarge*> m_GrdLarge;
};