#include "../include/camara.h"


Camara::Camara(SDL_Renderer *renderer) : _renderer(renderer) {
    camera_info.x = 0;
    camera_info.y = 0;
    camera_info.zoom = 1.4;
}





void Camara::updateCamera(){

    float pos_x =  escalador.worldToPixelX(worm->m_WormXPosition, worm->m_Widht);
    float pos_y = escalador.pixelToWorldY(worm->m_WormYPosition, worm->m_Height );
    //float widht = worm->m_Widht;
    //float height = worm->m_Height;

    int screenWidth = 512;
    int screenHeight = 512;

    camera_info.x = pos_x - (screenWidth/(2*camera_info.zoom));
    camera_info.y = pos_y - (screenHeight/(2*camera_info.zoom));
  

    camera_info.x = pos_x - (screenWidth/(2*camera_info.zoom));
    camera_info.y = pos_y - (screenHeight/(2*camera_info.zoom));


    SDL_RenderSetScale(_renderer, camera_info.zoom, camera_info.zoom);

    /*
    
    SDL_Rect camera_rect = {
        static_cast<int>((pos_x - camera_info.x) / camera_info.zoom),
        static_cast<int>((pos_y - camera_info.y) / camera_info.zoom),
        static_cast<int>(widht / camera_info.zoom),
        static_cast<int>(height / camera_info.zoom)
    };

    */
    
    
    //SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255); 
    //SDL_RenderFillRect(_renderer, &camera_rect);
    //SDL_RenderSetScale(_renderer, 1.0, 1.0);
}

void Camara::setWorm(Worm *worm) {
    this->worm = worm;
}




