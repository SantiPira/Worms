#include "../include/camara.h"


Camara::Camara(SDL_Renderer *renderer) : _renderer(renderer) {
    camera_info.zoom = 1.4f;
    camara_rect = {0,0, 512, 512};
}


void Camara::updateCamera(){

    SDL_RenderSetScale(_renderer, camera_info.zoom, camera_info.zoom);
    
    int player_x =  escalador.worldToPixelX(worm->m_WormXPosition, worm->m_Widht);
    int player_y = escalador.pixelToWorldY(worm->m_WormYPosition, worm->m_Height );


    camara_rect.x = player_x - (camara_rect.w/2);
    camara_rect.y = player_y - (camara_rect.h/2);
    
    
    if (camara_rect.x < 0) {camara_rect.x = 0;}
    if (camara_rect.y < 0) {camara_rect.y = 0;}
    if (camara_rect.x > camara_rect.w) {camara_rect.x = camara_rect.w;}
    if (camara_rect.y > camara_rect.h) {camara_rect.y = camara_rect.h;}

    SDL_Rect& worm_rect = worm->getWormRect();

    worm_rect.x = player_x - camara_rect.x;
    worm_rect.y = player_y - camara_rect.y;

    SDL_RenderFillRect(_renderer, &camara_rect);
    
    
}

void Camara::setWorm(Worm *worm) {
    this->worm = worm;
}




