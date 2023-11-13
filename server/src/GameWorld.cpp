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
    for (auto& action : userActions.get()) {
        b2Body * worm = worms.at(action.getIdPlayer());
        switch (action.getAction())
        {
            case MOVE:
                float movement_velocity;
                if(action.getParam1() == RIGHT) {
                    movement_velocity = 5.0f;
                } else {
                    movement_velocity = -5.0f;
                }
                worm->SetLinearVelocity(b2Vec2(movement_velocity, 0));
                break;
            case STOP_MOVE:
                worm->SetLinearVelocity(b2Vec2(0, 0));
                break;
            case JUMP:
            {
                b2Vec2 vel = worm->GetLinearVelocity();
                float epsilon = 0.1f; // Un pequeño valor para manejar errores de precisión
                if (std::abs(vel.y) < epsilon) {
                    // El cuerpo está en reposo en el eje Y y puede saltar
                    float impulse = worm->GetMass() * 5;
                    vel.y = impulse;
                    worm->ApplyLinearImpulse(vel, worm->GetWorldCenter(), true);
                }
                break;
            }
            default:
                break;
        }
    }
    m_world.Step(timeStep,velocityIterations,positionIterations);

    std::vector<GameUpdate> gameUpdates;
    for (auto& worm : worms) {
        GameUpdate gameState{};
        int id = worm.first;
        gameState.player_id = id;
        b2Vec2 position = worm.second->GetPosition();
        gameState.x_pos = position.x;
        gameState.y_pos = position.y;
        b2Vec2 tempPosition = wormsPositions.at(id);
        if (tempPosition != position) {
            std::cout << "ID [" << id << "] - POS (" << position.x << ", " << position.y << ")" << std::endl;
            wormsPositions.at(id) = position;
        }
        b2Vec2 vLineal = worm.second->GetLinearVelocity();
        if (vLineal.x > 0) {
            gameState.action = WORM_MOVE_RIGHT;
        } else if (vLineal.x < 0) {
            gameState.action = WORM_MOVE_LEFT;
        } else if (vLineal.y > 0) {
            gameState.action = WORM_JUMP;
        } else if (vLineal.y < 0) {
            gameState.action = WORM_FALL;
        } else {
            gameState.action = WORM_NONE;
        }
        gameUpdates.push_back(gameState);
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
	shape.SetAsBox(0.5f, 1.0f);
	b2FixtureDef fd;
    fd.friction = 0.0f;
	fd.shape = &shape;
	fd.density = 20.0f;
	body->CreateFixture(&fd);

    worms.insert(std::make_pair(player_number, body)); //worms.size()
    wormsPositions.insert(std::make_pair(player_number, b2Vec2(x_pos, y_pos)));
    std::cout << "ID [" << player_number << "] - POS (" << x_pos << ", " << y_pos << ")" << std::endl;
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

