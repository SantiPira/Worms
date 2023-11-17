#include "world/GameWorld.h"

GameWorld::GameWorld(const std::string &file_map_path) : players(1), width(20.0f), height(20.0f),
 timeStep(1.0f/60.0f), velocityIterations(8), positionIterations(3), gravity(0.0f,-10.0f),
 m_world(gravity), map_path(file_map_path) {}   /*TODO ESTO IRIA POR CONFIG YML*/

void GameWorld::Setup() {
    StartWorld();
    ParseMapFromFile parser;
    std::vector<Grd> girders = parser.parse(map_path);
    for (auto& girder : girders) {
        SetGirder(girder);
    }
}

void GameWorld::SetGirder(const Grd& girder) {
    if(girder.grdType == GRD_LARGE_HORIZONTAL) {
        b2BodyDef bd;
        bd.position.Set(girder.x, girder.y);
        bd.type = b2_staticBody;
        b2Body * body = m_world.CreateBody(&bd); 
        b2PolygonShape shape;
        b2FixtureDef myFixtureDef;
        shape.SetAsBox(5.0f,0.50f);
        myFixtureDef.shape = &shape;
        myFixtureDef.density = 1;
        body->CreateFixture(&myFixtureDef);
    }
}

void GameWorld::StartWorld() {
    b2BodyDef myBodyDef;
    b2PolygonShape polygonShape;

    //fixture definition    
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &polygonShape;
    myFixtureDef.density = 1;

    //a static body
    myBodyDef.type = b2_staticBody;
    myBodyDef.position.Set(0, 0);
    b2Body* staticBody = m_world.CreateBody(&myBodyDef);
    
    //add four walls to the static body
    polygonShape.SetAsBox( 10, 1, b2Vec2(10, -1), 0);//ground
    staticBody->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( 10, 1, b2Vec2(10, 21), 0);//ceiling
    staticBody->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( 1, 10, b2Vec2(-1, 10), 0);//left wall
    staticBody->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( 1, 10, b2Vec2(21, 10), 0);//right wall
    staticBody->CreateFixture(&myFixtureDef);
}

void GameWorld::SetWorm(const int& player_number, const float & x_pos, const float& y_pos) {
    auto* wormEntity = new WWorm(&m_world, player_number, x_pos, y_pos, x_pos <= width/2);
    worms.insert(std::make_pair(player_number, wormEntity));
    wormsPositions.insert(std::make_pair(player_number, b2Vec2(x_pos, y_pos)));
    std::cout << "ID [" << player_number << "] - POS (" << x_pos << ", " << y_pos << ")" << std::endl;
}

std::vector<GameUpdate> GameWorld::getWormsPosition() const {
    std::vector<GameUpdate> gameUpdates;
    for (auto& worm : worms) {
        gameUpdates.push_back(worm.second->getUpdate());
    }
    return gameUpdates;
}

GameUpdate GameWorld::execute(IWormInstruction *instruction, int playerId) {
    WWorm* worm = worms.at(playerId);
    instruction->execute(worm);
    step();
    return worm->getUpdate();
}

void GameWorld::step() {
    m_world.Step(timeStep,velocityIterations,positionIterations);
}

void GameWorld::removeWorm(int idPlayer) {
    m_world.DestroyBody(worms.at(idPlayer)->getBody());
    worms.erase(idPlayer);
    wormsPositions.erase(idPlayer);
}
