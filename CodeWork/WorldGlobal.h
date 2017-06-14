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


class WorldGlobal
{
public:


	void setWall(int x, int y, int w, int h)
	{
		b2PolygonShape gr;
		gr.SetAsBox(w / m_SCALEworld, h / m_SCALEworld);

		b2BodyDef bdef;
		bdef.position.Set(x / m_SCALEworld, y / m_SCALEworld);

		b2Body *b_ground = World.CreateBody(&bdef);
		b_ground->CreateFixture(&gr, 1);
	}


private:

	const float m_SCALEworld = 30.f;

};
#endif // !WORLDGLOBAL_h
