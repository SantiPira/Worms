#include "../include/GameWorld.h"

GameWorld::GameWorld(const std::string &file_map_path) : players(1), width(20.0f), height(20.0f),
 timeStep(1.0f/60.0f), velocityIterations(8), positionIterations(3), gravity(0.0f,-10.0f),
 m_world(gravity), map_path(file_map_path) {}

void GameWorld::Setup() {
    ParseMapFromFile parser;
    std::vector<Grd> girders = parser.parse(map_path);
    for (auto& girder : girders) {
        SetGirder(girder);
    }
}

GameUpdate GameWorld::UpdateWorld() {

    m_world.Step(timeStep,velocityIterations,positionIterations);
    GameUpdate update;
    return update;
}

void GameWorld::SetGirder(const Grd& girder) {
    if(girder.grdType == GRD_SMALL_HORIZONTAL) {
        b2BodyDef bd;
        bd.position.Set(float(girder.x),float(girder.y));
        bd.type = b2_staticBody;
        b2Body * body = m_world.CreateBody(&bd); 
        b2PolygonShape shape;
        b2FixtureDef myFixtureDef;
        shape.SetAsBox(3.0f,.25f);
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
    polygonShape.SetAsBox( 10, 1, b2Vec2(0, 0), 0);//ground
    staticBody->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( 10, 1, b2Vec2(0, 20), 0);//ceiling
    staticBody->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( 1, 10, b2Vec2(-10, 10), 0);//left wall
    staticBody->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( 1, 10, b2Vec2(10, 10), 0);//right wall
    staticBody->CreateFixture(&myFixtureDef);
}

void GameWorld::SetWorm(const int& player_number, const float & x_pos, const float& y_pos) {

    b2Body * body;

	b2BodyDef bd;
	bd.position.Set(x_pos, y_pos);
	bd.type = b2_dynamicBody;
	bd.fixedRotation = true;
	bd.allowSleep = false;
	body = m_world.CreateBody(&bd);
	b2PolygonShape shape;
	shape.SetAsBox(0.25f, 0.25f);
	b2FixtureDef fd;
	fd.shape = &shape;
	fd.density = 20.0f;
	body->CreateFixture(&fd);

    worms.insert(std::make_pair(player_number, body)); //worms.size()
}

