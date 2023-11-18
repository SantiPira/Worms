#include "../include/GameClient.h"

void GameClient::Init(const std::vector<Grd>& vector, int idPlayer, std::vector<GameUpdate>& initInfo) {
    InitSDL();
    CreateWindowAndRender();
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    m_IdPlayer = idPlayer;
    for (auto& grd : vector) {
        auto* grdL = new GrdLarge(_renderer, grd.x, grd.y, grd.width, grd.height);
        grdL->init();
        m_GrdLarge.push_back(grdL);
    }

    for (auto& gameUpdate : initInfo) {
        auto* worm = new Worm(_renderer, gameUpdate.x_pos, gameUpdate.y_pos, gameUpdate.width, gameUpdate.height);
        worm->init();
        m_Worms.insert(std::make_pair(gameUpdate.player_id, worm));
    }
}

void GameClient::InitSDL() {
    auto isInitialized = SDL_Init(SDL_INIT_VIDEO) >= 0;

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

void GameClient::Update(double elapsedSeconds, const GameUpdate& gameUpdate) {
    if (gameUpdate.m_Move == GameAction::INVALID_ACTION) {
        return;
    }
    m_Worms.at(gameUpdate.player_id)->update(elapsedSeconds, gameUpdate);
    if (gameUpdate.m_SelfCondition == GameAction::WORM_GRAVE) {
        m_WormsDie.push_back(m_Worms.at(gameUpdate.player_id));
        m_Worms.erase(gameUpdate.player_id);
    }
}

void GameClient::Render() {
    SDL_RenderClear(_renderer);

    for (auto& grdL : m_GrdLarge) {
        grdL->render();
    }

    for (auto& worm : m_Worms) {
        worm.second->render();
    }

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


