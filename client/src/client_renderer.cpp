#include "client_renderer.h"

ClientRenderer::ClientRenderer(ProtectedQueue<std::string>& queue, std::atomic<bool>& game_status, std::vector<Grd>& map_info, Protocol& protocol): 
message_queue(queue), keep_playing(game_status), map_info(map_info), protocol(protocol) {}

void ClientRenderer::run() { 

    auto game = GameClient();
    auto lastTime = std::chrono::system_clock::now();

    GameUpdate gameUpdate = protocol.recvGameUpdate();
    ProtectedQueue<std::string> settingsQueue(100);
    ProtectedQueue<GameUpdate> gameUpdates(100);
    gameUpdates.push(gameUpdate);

    EventSender eventSender(protocol, 1, std::ref(settingsQueue));
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

