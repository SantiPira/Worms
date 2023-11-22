#pragma once

#include <atomic>
#include <unordered_set>
#include "../../common_libs/include/Thread.h"
#include "world/GameWorld.h"
#include "messages/user_actions/UserAction.h"
#include "world/instructions/InstructionFactory.h"

#define MAX_TURN_SECONDS 120

class Game : public Thread {
 private:
    int m_IdGame;
    std::string m_GameName;
    std::string m_MapName;
    int m_Players;
    std::unordered_map<int, ProtectedQueue<GameUpdate>*> m_QClientUpdates; //TODO: Change string to GameUpdate later
    ProtectedQueue<UserAction> m_InputActions;
    std::atomic<bool> m_KeepRunning;
    int m_PopMessageQuantity;
    GameWorld world;

public:
    Game(int id, std::string gameName, std::string mapName, int players);
    void run() override;
    int getIdGame() const;
    std::string getGameName() const;
    std::string getMapName() const;
    int getPlayers() const;
    int addPlayer(ProtectedQueue<GameUpdate>* qClientUpdates);
    ProtectedQueue<UserAction>* getInputActions();
    void stop();
    ~Game() override = default;
    Game(const Game&) = delete;
    Game(Game&& other) = delete;

    bool isReadyToStart();

    std::unordered_map<int, ProtectedQueue<GameUpdate>*>* getClientUpdates();
    void setupWorld();
    void updateWorld();
    bool isStillPlayable();
    void kill();

private:
    void pushSetToClients(std::reference_wrapper<std::unordered_set<GameUpdate, GameUpdateHash>> updates);
    void pushUpdatesToClients(std::reference_wrapper<std::vector<GameUpdate>> updates);
    void pushUpdateToClients(GameUpdate& update);
    void sendInfoTurns(int playerId, GameAction infoTurn);

    GameUpdate &buildTransitionUpdate();
};
