//#include "Ball.h"
//
//
////------------------------------------------------------------------------------------------------
//
//Ball::Ball(float radius, bool contact) : m_contacting(contact)
//{
//	m_body = NULL;
//	m_radius = radius;
//
//	//set up dynamic body, store in class variable
//	b2BodyDef myBodyDef;
//	myBodyDef.type = b2_dynamicBody;
//	myBodyDef.position.Set(4, 1);
//	m_body = World.CreateBody(&myBodyDef);
//
//	//position.Set(double x, double y) - eine Grundbox wird erstellt mit den Koordinaten x 
//	b2CircleShape circle;
//	circle.m_radius = radius / 30.f;
//
//	b2FixtureDef fdef;
//	fdef.shape = &circle;
//	fdef.restitution = 0.95f;
//	fdef.density = 0.2f;
//
//	m_body->CreateFixture(&fdef);
//	m_body->SetUserData("ball");
//}
//
////----------------------------------------------------------------------------------------------------
//
//void Ball::initSpeed()
//{
//	//ball max speed
//	vel = m_body->GetLinearVelocity();
//	if (vel.Length()>15) m_body->SetLinearVelocity(15 / vel.Length() * vel);
//}
//
////----------------------------------------------------------------------------------------------------
//
//void Ball::counting()
//{
//	if (m_contacting == true)
//	{
//		m_player->incrementScorePlayer1();
//		m_player->incrementScorePlayer2();
//	}
//}
//
////----------------------------------------------------------------------------------------------------
//
//void Ball::startContactBall() { m_contacting = true; }
//void Ball::endContactBall() { m_contacting = false; }
//
////----------------------------------------------------------------------------------------------------
