#include "world/GameWorld.h"

GameWorld::GameWorld(const std::string &file_map_path) : players(1), width(20.0f), height(20.0f),
 timeStep(1.0f/60.0f), velocityIterations(8), positionIterations(3), gravity(0.0f,-10.0f),
 m_world(gravity), map_path(file_map_path) {}   /*TODO ESTO IRIA POR CONFIG YML*/

void GameWorld::Setup() {
    categories = {m_WormCategory};
    StartWorld();
    ParseMapFromFile parser;
    std::vector<Grd> girders = parser.parse(map_path);
//    for (auto& girder : girders) {
//        SetGirder(girder);
//    }
    SetGirder(girders[0]);
    m_WWater = std::make_unique<WWater>(&m_world, categories);
    m_world.SetContactListener(&contactListener);
}

void GameWorld::SetGirder(const Grd& girder) {
    if(girder.grdType == GRD_LARGE_HORIZONTAL) {
        b2BodyDef bd;
        bd.position.Set(5.0f, 9.5f);
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
    auto* wormEntity = new WWorm(&m_world, player_number, x_pos, y_pos, x_pos <= width/2, m_WormCategory,
                                 {m_WormCategory, m_WaterCategory});
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

void GameWorld::execute(IWormInstruction *instruction, int playerId) {
    if (playerId == -1) {
        return;
    }
    WWorm* worm = worms.at(playerId);
    instruction->execute(worm);
//    step();
//    return worm->getUpdate();
}

void GameWorld::step() {
    m_world.Step(timeStep,velocityIterations,positionIterations);
}

void GameWorld::removeDeadWorms(std::reference_wrapper<std::vector<GameUpdate>> updates) {
    std::vector<int> wormsToRemove;
    for (auto& worm : worms) {
        if (worm.second->getSelfCondition() == WORM_DIE) {
            auto up = worm.second->getUpdate();
            up.m_SelfCondition = WORM_GRAVE;
            updates.get().push_back(up);
            wormsToRemove.push_back(worm.first);
            setStaticBody(worm);
        }
    }

    for (auto& id : wormsToRemove) {
        m_world.DestroyBody(worms.at(id)->getBody());
        worms.erase(id);
        wormsPositions.erase(id);
    }
}

void GameWorld::setStaticBody(std::pair<const int, WWorm *> &worm) {
    b2BodyDef bd;
    bd.position.Set(worm.second->getPosition().x, worm.second->getPosition().y);
    bd.type = b2_staticBody;
    b2Body * body = m_world.CreateBody(&bd);
    b2PolygonShape shape;
    b2FixtureDef myFixtureDef;
    shape.SetAsBox(0.8f,0.5f);
    myFixtureDef.shape = &shape;
    myFixtureDef.density = 1;
    body->CreateFixture(&myFixtureDef);
}

GameWorld::~GameWorld() {
    for (auto& worm : worms) {
        m_world.DestroyBody(worm.second->getBody());
        delete worm.second; //TODO: Revisar esto
    }
}

