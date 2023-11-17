#include "../include/camara.h"


Camara::Camara(SDL_Renderer *renderer) : _renderer(renderer) {
    camera_info.x = 0;
    camera_info.y = 0;
    camera_info.zoom = 1;
}

void Camara::updateCamera(){

    float pos_x = worm->m_WormXPosition;
    float pos_y = worm->m_WormYPosition;

    float widht = worm->m_Widht;
    float height = worm->m_Height;
    // Antes de ajustar la matriz de transformación (SDL_RenderSetScale), calcula el desplazamiento de la cámara para centrar el gusano.
    int screenWidth = 512;
    int screenHeight = 512;

    // Calcular la posición centrada del gusano en la pantalla después del zoom.
    int centeredX = static_cast<int>(pos_x * camera_info.zoom - camera_info.x + screenWidth / 2);
    int centeredY = static_cast<int>(pos_y * camera_info.zoom - camera_info.y + screenHeight / 2);

    // Ajustar la posición de la cámara para que el gusano permanezca en el centro después del zoom.
    camera_info.x = static_cast<int>(pos_x * camera_info.zoom - screenWidth / 2);
    camera_info.y = static_cast<int>(pos_y * camera_info.zoom - screenHeight / 2);

    SDL_RenderSetScale(_renderer, camera_info.zoom, camera_info.zoom);

    // Luego, al renderizar objetos, utiliza la posición centrada.
    SDL_Rect objRect = {
        centeredX,
        centeredY,
        static_cast<int>(widht * camera_info.zoom),
        static_cast<int>(height * camera_info.zoom)
    };

    SDL_RenderFillRect(_renderer, &objRect);
}

void Camara::setWorm(Worm *worm) {
    this->worm = worm;
}




