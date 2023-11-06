#pragma once

#include <SDL.h>
#include <SDL2pp/SDL.hh>
#include <SDL2pp/SDL2pp.hh>
#include <vector>

class FactoryTexture {
private:
    std::vector<SDL2pp::Texture> textures;
public:
    FactoryTexture(SDL2pp::Renderer* renderer, std::vector<std::string>& paths);
    std::vector<SDL2pp::Texture*> getTextures();
};