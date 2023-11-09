#include "../include/GameClient.h"

void GameClient::Init() {
    InitSDL();
    CreateWindowAndRender();
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);


    SDL_Surface *surfaceTemp = IMG_Load("/home/santipira/CLionProjects/SDL-Project/SDLProject/LoadImages/resources/logo.png");
    _logoTexture = SDL_CreateTextureFromSurface(_renderer, surfaceTemp);
    SDL_QueryTexture(_logoTexture, NULL, NULL, &_sourceLogoRect.w, &_sourceLogoRect.h);
    _destLogoRect.x = 0;
    _destLogoRect.y = 0;
    _destLogoRect.w = 150;
    _destLogoRect.h = 150;
    SDL_FreeSurface(surfaceTemp);

    surfaceTemp = IMG_Load("/home/santipira/CLionProjects/SDL-Project/SDLProject/LoadImages/resources/hero_walk.png");
    _heroTexture = SDL_CreateTextureFromSurface(_renderer, surfaceTemp);
    //SDL_QueryTexture(_heroTexture, NULL, NULL, &_sourceHeroRect.w, &_sourceHeroRect.h);
    _frameIndex = 0;
    _sourceHeroRect.x = _frameIndex * 587;
    _sourceHeroRect.y = 0;
    _sourceHeroRect.w = 587;
    _sourceHeroRect.h = 707;
    _destHeroRect.x = 0;
    _destHeroRect.y = 155;
    _destHeroRect.w = 195;
    _destHeroRect.h = 235;
    SDL_FreeSurface(surfaceTemp);

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

void GameClient::Update() {
    _frameIndex = int(((SDL_GetTicks() / 100) % 10));

    _sourceHeroRect.x = _frameIndex * 587;

    _destHeroRect.x += 1;

}

void GameClient::Render() {
    SDL_RenderClear(_renderer);

    // renderizar imagenes, etc.
    SDL_RenderCopy(_renderer, _logoTexture, &_sourceLogoRect, &_destLogoRect);
    SDL_RenderCopyEx(_renderer, _heroTexture, &_sourceHeroRect, &_destHeroRect, 0, NULL, SDL_FLIP_NONE);

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