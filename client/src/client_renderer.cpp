#include "client_renderer.h"

ClientRenderer::ClientRenderer(ProtectedQueue<std::string>& queue, std::atomic<bool>& game_status, std::vector<Grd>& map_info): 
message_queue(queue), keep_playing(game_status), map_info(map_info) {}


void ClientRenderer::initialize_renderer() {

    //SDL sdl(SDL_INIT_VIDEO);


    std::cout << "Entre al inicializador\n";

    //sdl = std::make_unique<SDL>(SDL_INIT_VIDEO);
    //std::cout << "Cree un coso de sdl\n";

    game_window = new Window("Worms", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800,SDL_WINDOW_RESIZABLE);
    std::cout << "Cree una ventana\n";

    renderer = new Renderer(*this->game_window, -1, SDL_RENDERER_ACCELERATED);
    std::cout << "Cree un renderer\n";
}



void ClientRenderer::run() { 

    std::cout << "SOY EL RENDERER Y ACABO DE LANZARME\n";

    // inicializador.
    this->initialize_renderer();
    
    while (!this->keep_playing)
    {

        std::cout << "ACABO DE ENTRAR AL WHILE\n";


        this->renderer->Clear();
        this->renderer->Present();
        
        //pop
        //proceso
        //renderizo


    }
    
    std::cout << "Soy el renderer y acabo de terminar\n";
}

