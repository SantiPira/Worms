#pragma once

#include "../../../Box2D/include/box2d/box2d.h"
#include "ProtectedQueue.h"
#include "ParseMapFromFile.h"
#include "messages/server/GameUpdate.h"
#include "TurnHandler.h"
#include "messages/user_actions/UserAction.h"
#include "world/entities/WWorm.h"
#include "world/entities/WWater.h"
#include "world/entities/WBeam.h"
#include "world/entities/WDeadWorm.h"
#include "world/instructions/IWormInstruction.h"
#include "world/listeners/ContactListener.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <memory>

class GameWorld {
private:
    int players;
    const float width;
    const float height;
    const float timeStep;
    int32 velocityIterations;
    int32 positionIterations;
    const b2Vec2 gravity;
    b2World m_world;
    const std::string& map_path; 
    std::unordered_map<int, WWorm*> worms;
    int i = 0;
    std::unordered_map<int, b2Vec2> wormsPositions;
    std::unique_ptr<WWater> m_WWater;
    std::vector<std::unique_ptr<WBeam>> m_Beams;
    std::unordered_map<int, WDeadWorm*> deadWorms;

    uint16_t m_GroundCategory = 0x0001;
    uint16_t m_BeamCategory = 0x0002;
    uint16_t m_WormCategory = 0x0003;
    uint16_t m_WaterCategory = 0x0004;
    std::vector<uint16_t> categories;
    ContactListener contactListener;

public:

    explicit GameWorld(const std::string &map_path);
    void Setup();
    void StartWorld();
    void SetWorm(const int& player_number, const float & x_pos, const float& y_pos);
    void execute(IWormInstruction* instruction, int playerId);
    std::vector<GameUpdate> getWormsUpdates(bool getAll, bool playingStatus) const;

    void step();

    void removeDeadWorms(std::vector<int> &wormsRemoved);

    void setStaticBody(std::pair<const int, WWorm *> &worm);

    //destructor
    ~GameWorld();

    void resetWormStatus(int idPlayer);

    bool isQuiet();

    void getDeadWormsIds(std::vector<int>& deadWormsIds);

    void passAway(int &id);

    bool isAlive(int idPlayer);

    bool wormBrokeTurn(const UserAction& userAction);

    bool wormsAlive(std::vector<int>& idsDeadWorms);
};
