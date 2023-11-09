#ifndef CLIENT_REDERER_H
#define CLIENT_REDNERER_H

#include "../../common_libs/include/Thread.h"
#include "../../common_libs/include/ProtectedQueue.h"
#include "../../common_libs/include/ParseMapFromFile.h"

#include <atomic>
#include <SDL2pp/SDL2pp.hh>
#include <memory>


using namespace SDL2pp;
using namespace std;

class ClientRenderer: public Thread {
    private:
    ProtectedQueue<std::string>& message_queue;
    atomic<bool>& keep_playing;
    std::vector<Grd>& map_info;

    std::unique_ptr<SDL> sdl;
    Window* game_window{NULL};
    Renderer* renderer{NULL};
    SDL* sound_mixer{NULL};
    Chunk* main_music{NULL};

    
    void initialize_renderer();

    public:

   ClientRenderer(ProtectedQueue<std::string>& queue, std::atomic<bool>& game_status, std::vector<Grd>& map_info); 

    void run() override;



//GUIA DE USUARIO
//MANUAL DE PROYECTO.
//Docu tecnica.
//Instalador.


};


#endif

