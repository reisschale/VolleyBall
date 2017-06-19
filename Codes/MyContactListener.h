#pragma once
#ifndef MYCONTACTLISTENER_H
#include <Box2D\Box2D.h>
#include "Ball.h"
#include "WorldGlobal.h"
#include "Player.h"
#include <iostream>

class MyContactListener: public b2ContactListener
{
void BeginContact(b2Contact* contact) {

	//check if fixture A was a ball
	void* bodyUserData = contact->GetFixtureA()->GetUserData();
	//if (bodyUserData == m_ball->getName() )
	//{
	//	//static_cast<Ball*>(bodyUserData)->startContactBall();
	//	//static_cast<Player*>(bodyUserData)->incrementScorePlayer1();
	//
	//}
	
	std::cout << "Kontakt" << std::endl;

	////check if fixture B was a ball
	 bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
	if (bodyUserData == "wall")
	{
		static_cast<WorldGlobal*>(bodyUserData)->startContact();
	}
	

	//m_player->incrementScorePlayer1();
	
}

void EndContact(b2Contact* contact) {

	//check if fixture A was a ball
	void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
	if (bodyUserData == "ball")
	{
		static_cast<Ball*>(bodyUserData)->endContactBall();
		
	}

	////check if fixture B was a ball
	bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
	if (bodyUserData == "wall")
	{
		static_cast<WorldGlobal*>(bodyUserData)->endContact();
	}

	std::cout << "kein Kontakt" << std::endl;
	}

private:
	Ball* m_ball;
	Player* m_player;
};
#endif // !MYCONTACTLISTENER_H
