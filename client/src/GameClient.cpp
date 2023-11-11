#include "../include/GameClient.h"

void GameClient::Init(const std::vector<Grd>& vector) {
    InitSDL();
    CreateWindowAndRender();
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);

    for (auto& grd : vector) {
        auto* grdL = new GrdLarge(_renderer, grd.x, grd.y);
        grdL->init();
        m_GrdLarge.push_back(grdL);
    }

    Worm* worm = new Worm(_renderer, 10, 8.5);
    worm->init();
    m_Worms.push_back(worm);

    Worm* worm2 = new Worm(_renderer, 0, 8.5);
    worm2->init();
    m_Worms.push_back(worm2);

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
    SDL_CreateWindowAndRenderer(1024, 1024, SDL_WINDOW_SHOWN, &_window, &_renderer);
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

void GameClient::Update(double elapsedSeconds, const GameUpdate& gameUpdate) {
    for (auto& worm : m_Worms) {
        worm->update(elapsedSeconds, gameUpdate.x_pos, gameUpdate.y_pos);
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