#include "../../Box2D/include/box2d/box2d.h"
#include "../../common_libs/include/ProtectedQueue.h"
#include "TurnHandler.h"
#include <fstream>
#include <sstream>

class GameWorld {
private:
    int beams;
    int players;
    float width;
    float height;
    b2Vec2 gravity;
    b2World m_world;
public:

    GameWorld(const std::string &map_path);
    void UpdateWorld();
    //void SetBeam();
    //void StartWorld();
    //void SetWorm();

};
