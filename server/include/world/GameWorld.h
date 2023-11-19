#include "../../../Box2D/include/box2d/box2d.h"
#include "ProtectedQueue.h"
#include "ParseMapFromFile.h"
#include "messages/server/GameUpdate.h"
#include "TurnHandler.h"
#include "messages/user_actions/UserAction.h"
#include "world/entities/WWorm.h"
#include "world/entities/WWater.h"
#include "world/instructions/IWormInstruction.h"
#include "world/listeners/ContactListener.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <memory>

class GameWorld {
private:
    int beams;
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

    uint16_t m_GroundCategory = 0x0001;
    uint16_t m_BeamCategory = 0x0002;
    uint16_t m_WormCategory = 0x0003;
    uint16_t m_WaterCategory = 0x0004;
    std::vector<uint16_t> categories;
    ContactListener contactListener;

public:

    explicit GameWorld(const std::string &map_path);
    void Setup();
    void SetGirder(const Grd& girder);
    void StartWorld();
    void SetWorm(const int& player_number, const float & x_pos, const float& y_pos);
    void execute(IWormInstruction* instruction, int playerId);
    std::vector<GameUpdate> getWormsPosition() const;

    void step();

    void removeDeadWorms(std::reference_wrapper<std::vector<GameUpdate>> updates);

    void setStaticBody(std::pair<const int, WWorm *> &worm);

    //destructor
    ~GameWorld();
};
