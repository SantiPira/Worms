#include "../include/GameClient.h"

void GameClient::Init(const std::vector<Grd> vector) {
    InitSDL();
    CreateWindowAndRender();
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);

    Worm* worm = new Worm(_renderer, 0, 0);
    worm->init();
    m_Worms.push_back(worm);

    Worm* worm2 = new Worm(_renderer, 100, 100);
    worm2->init();
    m_Worms.push_back(worm2);

    auto grdL = new GrdLarge(_renderer, vector[0].x, vector[0].y);
    grdL->init();
    m_GrdLarge.push_back(grdL);

    _isRunning = true;
}

void GameClient::InitSDL() {
    auto isInitialized = SDL_Init(SDL_INIT_VIDEO) >= 0;

    if (!isInitialized) {
        std::cout << "Exception" << std::endl;
        //throw SDL_Exception(SDL_GetError());
    }
}

void GameClient::CreateWindowAndRender() {
    SDL_CreateWindowAndRenderer(512, 512, SDL_WINDOW_SHOWN, &_window, &_renderer);
    if (_window == NULL || _renderer == NULL) {
        //throw SDL_Exception(SDL_GetError());
        std::cout << "Exception" << std::endl;
    }
}


void GameClient::HandleEvents() {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            _isRunning = false;
        }
    }
}

void GameClient::Update(double elapsedSeconds) {
    for (auto& worm : m_Worms) {
        worm->update(elapsedSeconds);
    }
}

void GameClient::Render() {
    SDL_RenderClear(_renderer);

    for (auto& grdL : m_GrdLarge) {
        grdL->render();
    }

    for (auto& worm : m_Worms) {
        worm->render();
    }
    SDL_RenderPresent(_renderer);
}

void GameClient::Release() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

bool GameClient::IsRunning() {
    return _isRunning;
}