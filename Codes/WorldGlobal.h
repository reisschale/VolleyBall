#pragma once
#ifndef WORLDGLOBAL_h
#define WORLDGLOBAL_h

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <sstream>

//Setup the worlds properties
b2Vec2 Gravity(0.f, 9.8f);

//Create the world
b2World World(Gravity);

b2PolygonShape shape;
b2BodyDef bdef;

b2Vec2 pos;
b2Vec2 vel;


class WorldGlobal
{
public:
	

	WorldGlobal(int x, int y, int w, int h, bool contactWall) 
		:m_x(x), m_y(y), m_w(w), m_h(h) , m_contactingWall(contactWall)
	{
		m_bodyWall = NULL;
		

		b2PolygonShape gr;
		gr.SetAsBox(m_w / m_SCALEworld, m_h / m_SCALEworld);
	

		b2BodyDef bWalldef;
		bWalldef.position.Set(m_x / m_SCALEworld, m_y / m_SCALEworld);
		bWalldef.type = b2_staticBody;
		m_bodyWall = World.CreateBody(&bWalldef);
	
		m_bodyWall->CreateFixture(&gr, 1);
		m_bodyWall->SetUserData("wall");
	}

	void startContact() { m_contactingWall = true; }
	void endContact() { m_contactingWall = false; }

	

private:
	int m_x, m_y, m_w, m_h;
	const float m_SCALEworld = 30.f;
	
	bool m_contactingWall;
	b2Body* m_bodyWall;
	
};
#endif // !WORLDGLOBAL_h

