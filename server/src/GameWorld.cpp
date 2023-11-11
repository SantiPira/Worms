#include "../include/GameWorld.h"

GameWorld::GameWorld(const std::string &file_map_path) : players(1), width(20.0f), height(20.0f),
 timeStep(1.0f/60.0f), velocityIterations(8), positionIterations(3), gravity(0.0f,-10.0f),
 m_world(gravity), map_path(file_map_path) {}

void GameWorld::Setup() {
    StartWorld();
    ParseMapFromFile parser;
    std::vector<Grd> girders = parser.parse(map_path);
    for (auto& girder : girders) {
        SetGirder(girder);
    }
}

std::vector<GameUpdate> GameWorld::UpdateWorld(std::reference_wrapper<std::vector<UserAction>> userActions) {
    std::vector<GameUpdate> gameUpdates;
    for (auto& worm : worms) {
        for (auto& action : userActions.get()) {
            if (action.getIdPlayer() == worm.first) {
                if (action.getAction() == MOVE) {
                    if (action.getParam1() == RIGHT) {
                        worm.second->SetLinearVelocity(b2Vec2(5.0f, 0));
                    } else {
                        worm.second->SetLinearVelocity(b2Vec2(-5.0f, 0));
                    }
                } else if (action.getAction() == STOP_MOVE) {
                    worm.second->SetLinearVelocity(b2Vec2(0, 0));
                }
            }
        }
    }
    m_world.Step(timeStep,velocityIterations,positionIterations);
    for (auto& worm : worms) {
        b2Vec2 position = worm.second->GetPosition();
        b2Vec2 velocity = worm.second->GetLinearVelocity();
        std::cout << " Position: " << position.x << " " << position.y << std::endl;
        if (velocity.x < 0) {
            GameUpdate gameUpdate{static_cast<uint8_t>(worm.first), WORM_MOVE_LEFT, position.x, position.y};
            gameUpdates.push_back(gameUpdate);
        } else if (velocity.x > 0) {
            GameUpdate gameUpdate{static_cast<uint8_t>(worm.first), WORM_MOVE_RIGHT, position.x, position.y};
            gameUpdates.push_back(gameUpdate);
        } else {
            GameUpdate gameUpdate{static_cast<uint8_t>(worm.first), WORM_IDLE, position.x, position.y};
            gameUpdates.push_back(gameUpdate);
        }
//        GameUpdate gameUpdate{static_cast<uint8_t>(worm.first), WORM_MOVE, position.x, position.y};
//        gameUpdates.push_back(gameUpdate);
    }

    return gameUpdates;
}

void GameWorld::SetGirder(const Grd& girder) {
    if(girder.grdType == GRD_LARGE_HORIZONTAL) {
        b2BodyDef bd;
        bd.position.Set(float(girder.x + (5.0f)),float(girder.y));
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

    b2Body * body;

	b2BodyDef bd;
	bd.position.Set(x_pos, y_pos + 0.50f); //10 11
	bd.type = b2_dynamicBody;
	bd.fixedRotation = true;
	bd.allowSleep = false;
	body = m_world.CreateBody(&bd);
	b2PolygonShape shape;
	shape.SetAsBox(1.0f, 1.0f);
	b2FixtureDef fd;
    fd.friction = 0.0f;
	fd.shape = &shape;
	fd.density = 20.0f;
	body->CreateFixture(&fd);

    worms.insert(std::make_pair(player_number, body)); //worms.size()
}

std::vector<GameUpdate> GameWorld::getWormsPosition() const {
    std::vector<GameUpdate> gameUpdates;
    for (auto& worm : worms) {
        b2Vec2 position = worm.second->GetPosition();
        GameUpdate gameUpdate{static_cast<uint8_t>(worm.first), WORM_IDLE, position.x, position.y};
        gameUpdates.push_back(gameUpdate);
    }
    return gameUpdates;
}

