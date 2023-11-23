#pragma once

#include <atomic>
#include <unordered_set>
#include "../../common_libs/include/Thread.h"
#include "world/GameWorld.h"
#include "messages/user_actions/UserAction.h"
#include "world/instructions/InstructionFactory.h"

enum class GameState {
    PLAYING,
    TURN_TRANSITION,
    GRACE_PERIOD
};

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
    GameState m_GameState;

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
    void pushSetToClients(std::reference_wrapper<std::vector<GameUpdate>> updates);
    void pushUpdatesToClients(std::reference_wrapper<std::vector<GameUpdate>> updates);
    void pushUpdateToClients(GameUpdate& update);
    void sendInfoTurns(int playerId, GameAction infoTurn);

    void processTurns(TurnHandler& turnHandler, InstructionFactory& instructionFactory);
    bool processUserActions(std::vector<UserAction>& userActions,
                            std::vector<GameUpdate>& updates,
                            InstructionFactory& instructionFactory, size_t& idxInstruction);

    void processTransitionAction(std::vector<UserAction> &userActions, InstructionFactory &instructionFactory,
                                 size_t &idxInstruction);
    void waitFrameTime();
    void endTurn(TurnHandler& turnHandler);

    GameUpdate &buildTransitionUpdate();
};
