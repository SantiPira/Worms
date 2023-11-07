#pragma once

#include <SDL2/SDL.h>
#include "SDL2pp/Renderer.hh"
#include "FactoryTexture.h"


class ToolBar {
private:
    SDL2pp::Renderer* m_Renderer;
public:
    explicit ToolBar(SDL2pp::Renderer* renderer);
    void render();
};