#pragma once
#ifndef BALL_h
#define BALL_h

#include <Box2D/Box2D.h>
#include <SFML\Graphics.hpp>
#include "WorldGlobal.h"
#include "Player.h"




class Ball
{

	
//public:
//	Ball(float radius, bool contact);
//	
//
//	~Ball() {}
//	
//
//	void* getName() {return m_body->GetUserData();}
//
//	void initSpeed();
//
//	void counting();
//	
//	void startContactBall();
//	void endContactBall();

	
public:

	//------------------------------------------------------------------------------------------------

	Ball(float radius, bool contact) : m_contacting(contact)
	{
		m_body = NULL;
		m_radius = radius;

		//set up dynamic body, store in class variable
		b2BodyDef myBodyDef;
		myBodyDef.type = b2_dynamicBody;
		myBodyDef.position.Set(4, 1);
		m_body = World.CreateBody(&myBodyDef);

		//position.Set(double x, double y) - eine Grundbox wird erstellt mit den Koordinaten x 
		b2CircleShape circle;
		circle.m_radius = radius / 30.f;

		b2FixtureDef fdef;
		fdef.shape = &circle;
		fdef.restitution = 0.95f;
		fdef.density = 0.2f;

		m_body->CreateFixture(&fdef);
		m_body->SetUserData("ball");
	}

	//----------------------------------------------------------------------------------------------------

	void initSpeed()
	{
		//ball max speed
		vel = m_body->GetLinearVelocity();
		if (vel.Length()>15) m_body->SetLinearVelocity(15 / vel.Length() * vel);
	}

	//----------------------------------------------------------------------------------------------------

	void counting()
	{
		if (m_contacting == true)
		{
			m_player->incrementScorePlayer1();
			m_player->incrementScorePlayer2();
		}
	}

	//----------------------------------------------------------------------------------------------------

	void startContactBall() { m_contacting = true; }
	void endContactBall() { m_contacting = false; }

	//----------------------------------------------------------------------------------------------------

	
private:
	const float m_SCALEball = 30.f;
	bool m_contacting;



	b2Body* m_body;
	Player* m_player;
	float m_radius;


};

#endif