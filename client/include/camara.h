#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL2pp/SDL2pp.hh>
#include <iostream>
#include <filesystem>
#include "engine/entities/worms/Worm.h"
#include "ParseMapFromFile.h"
#include "engine/entities/grd/GrdLarge.h"
#include "engine/graphics/Texture.h"
#include "messages/server/GameUpdate.h"
#include <unordered_map>
#include <vector>
#include "../../common_libs/include/utils/WorldScale.h"

typedef struct {
    float x, y;
    float zoom;
} Camera_info;

class Camara {
 
    SDL_Renderer *_renderer;
    Worm *worm;
    Camera_info camera_info;
    WorldScale escalador;
    SDL_Rect camara_rect;

    //SDL_Rect& worm_rect;


 public:
    Camara(SDL_Renderer *renderer);

    void setWorm(Worm *worm);


    void updateCamera();


};