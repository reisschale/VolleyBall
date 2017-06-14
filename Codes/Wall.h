#pragma once
#ifndef Wall_h

#include <Box2D\Box2D.h>


const float SCALE = 30.f;
const float DEG = 57.29577f;

b2Vec2 Gravity(0.f, 9.8f);
b2World World(Gravity);

class Wall
{
public:

	void setWall(int x, int y, int w, int h)
	{
		b2PolygonShape gr;
		gr.SetAsBox(w / SCALE, h / SCALE);

		b2BodyDef bdef;
		bdef.position.Set(x / SCALE, y / SCALE);

		b2Body *b_ground = World.CreateBody(&bdef);
		b_ground->CreateFixture(&gr, 1);
	}

private:

};


#endif // !Wall_h
