#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <filesystem>

class GameClient {
public:
    void Init();

    void HandleEvents();

    void Update(double elapsedSeconds);

    void Render();

    void Release();

    bool IsRunning();

private:
    void InitSDL();

    void CreateWindowAndRender();

private:
    bool _isRunning;

    SDL_Window *_window;
    SDL_Renderer *_renderer;

    SDL_Texture *_logoTexture;
    SDL_Rect _sourceLogoRect;
    SDL_Rect _destLogoRect;

    SDL_Texture *_heroTexture;
    SDL_Rect _sourceHeroRect;
    SDL_Rect _destHeroRect;
    int _frameIndex;
    float _heroXPosition;
};