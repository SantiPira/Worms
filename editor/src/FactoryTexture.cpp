#include "../include/FactoryTexture.h"

FactoryTexture::FactoryTexture(SDL2pp::Renderer* renderer, std::vector<std::string>& paths) {
    for (auto& path : paths) {
        textures.emplace_back(*renderer, path);
    }
}

std::vector<SDL2pp::Texture *> FactoryTexture::getTextures() {
    std::vector<SDL2pp::Texture*> all_textures;
    for (auto& texture : textures) {
        all_textures.push_back(&texture);
    }
    return all_textures;
}
