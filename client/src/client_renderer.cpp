#include "client_renderer.h"

ClientRenderer::ClientRenderer(ProtectedQueue<std::string>& queue, std::atomic<bool>& game_status, std::vector<Grd>& map_info, Protocol& protocol): 
message_queue(queue), keep_playing(game_status), map_info(map_info), protocol(protocol) {}

void ClientRenderer::run() { 

    ProtectedQueue<std::string> settingsQueue(100);
    ProtectedQueue<GameUpdate> gameUpdates(100);

    auto game = GameClient(gameUpdates);
    auto lastTime = std::chrono::system_clock::now();

    //Info inicial.
    GameUpdate gameUpdate = protocol.recvGameUpdate();

    
    gameUpdates.push(gameUpdate);

    EventSender eventSender(protocol, gameUpdate.player_id, std::ref(settingsQueue));
    ClientReceiver receiver(protocol, std::ref(gameUpdates));

    game.Init(this->map_info);

    eventSender.start();
    receiver.start();

    while (game.IsRunning()) {
        auto current = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsedSeconds = current - lastTime;

        //game.HandleEvents();

        game.Update(elapsedSeconds.count());

        game.Render();
    }

    game.Release();
    receiver.join();
    eventSender.join();
}

