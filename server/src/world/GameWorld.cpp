#include "world/GameWorld.h"

GameWorld::GameWorld(const std::string &file_map_path) : players(1), width(20.0f), height(20.0f),
 timeStep(1.0f/60.0f), velocityIterations(6), positionIterations(2), gravity(0.0f,-10.0f),
 m_world(gravity), map_path(file_map_path) {}   /*TODO ESTO IRIA POR CONFIG YML*/

void GameWorld::Setup() {
    categories = {m_WormCategory};
    StartWorld();
    ParseMapFromFile parser;
    std::vector<Grd> girders = parser.parse(map_path);
    for (auto& girder : girders) {
        std::unique_ptr<WBeam> beam = std::make_unique<WBeam>(&m_world, girder);
        m_Beams.push_back(std::move(beam));
    }
    m_WWater = std::make_unique<WWater>(&m_world, categories);
    m_world.SetContactListener(&contactListener);
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
                                 {m_WaterCategory});
    worms.insert(std::make_pair(player_number, wormEntity));
    wormsPositions.insert(std::make_pair(player_number, b2Vec2(x_pos, y_pos)));
    std::cout << "ID [" << player_number << "] - POS (" << x_pos << ", " << y_pos << ")" << std::endl;
}

std::vector<GameUpdate> GameWorld::getWormsUpdates(bool getAll, bool playingStatus) const {
    std::vector<GameUpdate> gameUpdates;
    for (auto& worm : worms) {
        GameUpdate gameUpdate = playingStatus ? worm.second->getUpdatePlaying(getAll || worm.second->getWasChanged())
                : worm.second->getUpdateEndTurn(getAll);
        gameUpdates.push_back(gameUpdate);
    }
    return gameUpdates;
}

void GameWorld::execute(IWormInstruction *instruction, int playerId) {
    if (playerId == -1) {
        return;
    }
    WWorm* worm = worms.at(playerId);
    if (worm->getBody()->GetType() == b2_staticBody) {
        return;
    }
    instruction->execute(worm);
}

void GameWorld::step() {
    m_world.Step(timeStep,velocityIterations,positionIterations);
}

void GameWorld::removeDeadWorms(std::vector<int> &wormsRemoved) {
    for (auto& id : wormsRemoved) {
        WWorm* worm = worms.at(id);
        b2Vec2 pos = worm->getPosition();
        float widthWorm = worm->getWidth();
        float heightWorm = worm->getHeight();
        deadWorms.insert(std::make_pair(id, new WDeadWorm(&m_world, id, pos, widthWorm, heightWorm)));
        worms.erase(id);
        wormsPositions.erase(id);
        worm->getBody()->GetUserData().pointer = reinterpret_cast<uintptr_t>(nullptr);
        m_world.DestroyBody(worm->getBody());
        delete worm;
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

void GameWorld::resetWormStatus(int idPlayer) {
    worms.at(idPlayer)->resetWormStatus();
    m_world.Step(0,0,0);
}

bool GameWorld::isQuiet() {
    for (auto& worm : worms) {
        if (worm.second->getIsMoving()) {
            return false;
        }
    }
    return true;
}

void GameWorld::getDeadWormsIds(std::vector<int> &deadWormsIds) {
    for (auto& worm : worms) {
        if (worm.second->getHealth() == 0) {
            deadWormsIds.push_back(worm.first);
        }
    }
}

//void GameWorld::passAway(int &id) {
//    WWorm* worm = worms.at(id);
//    b2Vec2 pos = worm->getPosition();
//    float widthWorm = worm->getWidth();
//    float heightWorm = worm->getHeight();
//    deadWorms.insert(std::make_pair(id, new WDeadWorm(&m_world, id, pos, widthWorm, heightWorm)));
//    worms.erase(id);
//    wormsPositions.erase(id);
//    delete worm;
//}

bool GameWorld::isAlive(int idPlayer) {
    return worms.at(idPlayer)->getHealth() > 0;
}

bool GameWorld::wormBrokeTurn(const UserAction &userAction) {
    for (auto& worm : worms) {
        if (worm.second->getHealth() == 0) {
            return true;
        }
    }
    if (userAction.getAction() == ATTACK) {
        return true;
    }
    return false;
}

bool GameWorld::wormsAlive(std::vector<int> &idsDeadWorms) {
    for (auto& idWorm : idsDeadWorms) {
        if (worms.at(idWorm)->getSelfCondition() != WORM_GRAVE) {
            return true;
        }
    }
    return false;
}



