#pragma once
#ifndef BALL_h
#define BALL_h

#include <Box2D/Box2D.h>
#include <SFML\Graphics.hpp>


class Ball
{

	b2PolygonShape shape;
	b2BodyDef bdef;
	
public:
	void setBall()
	{
		//position.Set(double x, double y) - eine Grundbox wird erstellt mit den Koordinaten x 
		bdef.position.Set(5, 1);

		b2CircleShape circle;
		circle.m_radius = 32 / m_SCALEball;
		
		b2Body *b = World.CreateBody(&bdef);
		b2FixtureDef fdef;
		fdef.shape = &circle;
		fdef.restitution = 0.95;
		fdef.density = 0.2;
		b->CreateFixture(&fdef);
		b->SetUserData("ball");
	}
private:
	const float m_SCALEball = 30.f;

};

#endif