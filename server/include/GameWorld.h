#include "../../Box2D/include/box2d/box2d.h"
#include "../../common_libs/include/ProtectedQueue.h"
#include "../../common_libs/include/ParseMapFromFile.h"
#include "../../common_libs/include/messages/server/GameUpdate.h"
#include "TurnHandler.h"
#include "messages/user_actions/UserAction.h"
#include <fstream>
#include <sstream>
#include <unordered_map>

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
    std::unordered_map<int,b2Body*> worms; // Deberia ser un int, Worm donde Worm tenga dentro un b2Body
    int i = 0;
    std::unordered_map<int, b2Vec2> wormsPositions;
public:

    GameWorld(const std::string &map_path);
    void Setup();
    std::vector<GameUpdate> UpdateWorld(std::reference_wrapper<std::vector<UserAction>> userActions);
    void SetGirder(const Grd& girder);
    void StartWorld();
    void SetWorm(const int& player_number, const float & x_pos, const float& y_pos);

    std::vector<GameUpdate> getWormsPosition() const;
};
