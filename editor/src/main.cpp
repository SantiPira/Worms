#include <iostream>
#include <SDL2/SDL.h>
#include "SDL2pp/SDL.hh"
#include "SDL2pp/Window.hh"
#include "SDL2pp/Renderer.hh"
#include "ToolBar.h"

int main() {
    // Inicializa SDL2
    SDL2pp::SDL sdl(SDL_INIT_VIDEO);

    // Crea una ventana SDL con SDL2pp
    SDL2pp::Window window("Worms",
                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                          960, 720,
                          SDL_WINDOW_RESIZABLE);

    // Crea un renderer para la ventana
    SDL2pp::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);

    ToolBar toolBar(&renderer);

    // Mantén la ventana abierta hasta que se cierre
    bool quit = false;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    return 0;
}
