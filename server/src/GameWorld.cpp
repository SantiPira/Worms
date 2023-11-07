#include "../include/GameWorld.h"

GameWorld::GameWorld(const std::string &file_map_path) : players(1), gravity(0.0f,10.0f), m_world(gravity) {

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

    std::ifstream file(file_map_path);
    std::string current_line;

    if (!file.is_open()) {
        throw stderr;
    }

    if(!getline(file,current_line)) {
        throw stderr;
    }         
    std::istringstream current_line_istream(current_line);
    current_line_istream >> beams;

    for(int i = 0; i < beams;i++) {
        if(!getline(file,current_line)) {
            throw stderr;
        } 

        int type;
        float x;
        float y;
        b2BodyDef bd;

        std::istringstream line_istream(current_line);
        line_istream >> type >> x >> y;
        bd.position.Set(x,y);
        bd.type = b2_staticBody;

        b2Body * body = m_world.CreateBody(&bd); 

        b2PolygonShape shape;
        b2FixtureDef myFixtureDef;
        shape.SetAsBox(3.0f,.25f);
        myFixtureDef.shape = &shape;
        myFixtureDef.density = 1;

        body->CreateFixture(&myFixtureDef);
    }

    b2Body * body;

	b2BodyDef bd;
	bd.position.Set(5.0f, 10.0f);
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

}

void GameWorld::UpdateWorld() {

}
