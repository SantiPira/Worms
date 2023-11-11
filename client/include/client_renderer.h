#ifndef CLIENT_REDERER_H
#define CLIENT_REDNERER_H

#include "../../common_libs/include/Thread.h"
#include "../../common_libs/include/ProtectedQueue.h"
#include "../../common_libs/include/ParseMapFromFile.h"

#include <atomic>
#include <SDL2pp/SDL2pp.hh>
#include <memory>
#include "GameClient.h"
#include "EventSender.h"
#include "client_receiver.h"
#include "messages/server/GameUpdate.h"
#include "Protocol.h"


using namespace SDL2pp;
using namespace std;

class ClientRenderer: public Thread {
    private:
    ProtectedQueue<std::string>& message_queue;
    atomic<bool>& keep_playing;
    std::vector<Grd>& map_info;

    Protocol& protocol;
    public:

    ClientRenderer(ProtectedQueue<std::string>& queue, std::atomic<bool>& game_status, std::vector<Grd>& map_info, Protocol& protocol); 

    void run() override;



//GUIA DE USUARIO
//MANUAL DE PROYECTO.
//Docu tecnica.
//Instalador.


};


#endif

