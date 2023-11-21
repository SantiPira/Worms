#include "../include/GameClient.h"

void GameClient::Init(const std::vector<Grd>& beams, int idPlayer, std::vector<GameUpdate>& initInfo) {
    InitSDL();
    CreateWindowAndRender();
    InitMixerAndChunk();
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    m_IdPlayer = idPlayer;
    for (auto& beamMap : beams) {
        auto* beam = new Beam(_renderer, beamMap);
        beam->init();
        m_Beams.push_back(beam);
    }

    for (auto& gameUpdate : initInfo) {
        auto* worm = new Worm(_renderer, gameUpdate.x_pos, gameUpdate.y_pos, gameUpdate.width, gameUpdate.height);
        worm->init();
        m_Worms.insert(std::make_pair(gameUpdate.player_id, worm));
    }

    //Inicializo el cielo
    const SDL_Rect m_SourceRect = {0, 0, 4096, 2034};
    sky = new Texture(std::filesystem::current_path().concat(Cloud_Sky.c_str()).c_str(), _renderer, {false, 128, 128, 192});
    sky->init();
    sky->setSourceRect(&m_SourceRect);
    water = new Texture(std::filesystem::current_path().concat(Water.c_str()).c_str(), _renderer, {false, 128, 128, 192});
    water->init();
    const SDL_Rect srcWaterRect = {0, 385, 1024, 46};
    water->setSourceRect(&srcWaterRect);

    InitCamera();

    //Corro el audio con el chunk
    //mixer->PlayChannel(-1, *chunk, -1);

}

void GameClient::InitCamera() {
    camara = new Camara(_renderer);
    camara->setWorm(m_Worms.at(m_IdPlayer));
}

void GameClient::InitSDL() {
    auto isInitialized = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) >= 0;

    if (!isInitialized) {
        std::cout << "Exception" << std::endl;
        //throw SDL_Exception(SDL_GetError());
    }
}

void GameClient::CreateWindowAndRender() {
    SDL_CreateWindowAndRenderer(512, 512, SDL_WINDOW_SHOWN, &_window, &_renderer);
    if (_window == NULL || _renderer == NULL) {
        //throw SDL_Exception(SDL_GetError());
        std::cout << "Exception" << std::endl;
    }
}

void GameClient::InitMixerAndChunk() {
    mixer = new SDL2pp::Mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);
    
    chunk = new SDL2pp::Chunk(std::filesystem::current_path().concat(Game_Music.c_str()).c_str());
}

void GameClient::Update(double elapsedSeconds, const GameUpdate& gameUpdate) {
    if (gameUpdate.m_Movement == GameAction::INVALID_ACTION) {
        return;
    }
    m_Worms.at(gameUpdate.player_id)->update(elapsedSeconds, gameUpdate);
    if (gameUpdate.m_SelfCondition == GameAction::WORM_GRAVE) {
        m_WormsDie.push_back(m_Worms.at(gameUpdate.player_id));
        m_Worms.erase(gameUpdate.player_id);
    }
}

void GameClient::Render(const WormDie& wormDie) {
    SDL_RenderClear(_renderer);

    camara->updateCamera();

    //renderizar fondo.
    SDL_Rect m_DestRect = {0 - camara->camara_rect.x/4, 0 - camara->camara_rect.y/4, 512, 512};
    //SDL_Rect m_DestRect = {-15, -1, 512, 512};
    sky->render(&m_DestRect, false);
    const SDL_Rect m_DestRect2 = {0, 461, 1024, 51};
    water->render(&m_DestRect2, false);

    for (auto& beam : m_Beams) {
        beam->render();
    }

    
    for (auto& worm : m_Worms) {
        worm.second->render();
    }
    camara->updateCamera();

    for (auto& worm : m_WormsDie) {
        worm->render();
    }

    SDL_RenderPresent(_renderer);

}

void GameClient::Release() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}


