#include "../include/GameClient.h"

void GameClient::Init() {
    InitSDL();
    CreateWindowAndRender();
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);

    SDL_Surface *surfaceTemp = IMG_Load(std::filesystem::current_path().concat("/resources/Worms/waccuse.png").c_str());
    SDL_SetColorKey(surfaceTemp, SDL_TRUE, SDL_MapRGB(surfaceTemp->format, 128, 128, 192));
    //surfaceTemp = IMG_Load(std::filesystem::current_path().concat("/resources/waccuse.png").c_str());
            //IMG_Load("/home/santipira/CLionProjects/SDL-Project/SDLProject/LoadImages/resources/hero_walk.png");
    _heroTexture = SDL_CreateTextureFromSurface(_renderer, surfaceTemp);
    //SDL_QueryTexture(_heroTexture, NULL, NULL, &_sourceHeroRect.w, &_sourceHeroRect.h);
    _frameIndex = 0;    //36 SPRITES
    _sourceHeroRect.x = _frameIndex * 60;
    _sourceHeroRect.y = 0;
    _sourceHeroRect.w = 60;
    _sourceHeroRect.h = 59;
    _destHeroRect.x = 0;
    _destHeroRect.y = 155;
    _destHeroRect.w = 60;
    _destHeroRect.h = 60;
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

void GameClient::Update(double elapsedSeconds) {
    _frameIndex = (SDL_GetTicks() % (36 * 100)) / 100;

    _sourceHeroRect.y = _frameIndex * 60;

    _heroXPosition += 0.1 * elapsedSeconds;
    _destHeroRect.x = _heroXPosition;

}

void GameClient::Render() {
    SDL_RenderClear(_renderer);

    // renderizar imagenes, etc.
    SDL_RenderCopy(_renderer, _logoTexture, &_sourceLogoRect, &_destLogoRect);
    SDL_RenderCopyEx(_renderer, _heroTexture, &_sourceHeroRect, &_destHeroRect, 0, NULL, SDL_FLIP_HORIZONTAL);

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