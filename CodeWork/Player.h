#ifndef PLAYER_h
#define PLAYER_h

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "WorldGlobal.h"

b2Body *pBody[2];
b2PolygonShape shape;
b2BodyDef bdef;

class Player
{
public:

	void createPlayer() 
	{
	//Schleife für zwei Spieler
	for (int i = 0; i < 2; i++)
	{
		//Erstellt die Grundbox mit Koordinaten x= 20* i und y= 2
		bdef.position.Set(20 * i, 2);

		//Shapes für das Simulieren von Physikgesetzen und Aufprall mit anderen Objekten
		//z.B: Ball mit Spieler, Spieler mit Spieler
		b2CircleShape circle;
		circle.m_radius = 32 / m_SCALEplayer;
		circle.m_p.Set(0, 13 / m_SCALEplayer);


		pBody[i] = World.CreateBody(&bdef);
		pBody[i]->CreateFixture(&circle, 5);
		circle.m_radius = 25 / m_SCALEplayer;
		circle.m_p.Set(0, -20 / m_SCALEplayer);
		pBody[i]->CreateFixture(&circle, 5);
		pBody[i]->SetFixedRotation(true);
		}
	setScorePlayer1(16);
	setScorePlayer2(2);
	}


	void setPlayer()
	{
		pBody[0]->SetUserData("player1");
		pBody[1]->SetUserData("player2");
	};
	

	/***Spieler_1************************************************/

	int getScorePlayer1(){ return m_scorePlayer1; }

	void incrementScorePlayer1()
	{
		m_scorePlayer1 = m_scorePlayer1++;
	}
	void setScorePlayer1(int score)
	{
		m_scorePlayer1 = score;
	}
	
	/**************************************************************/


	/***Spieler_2**************************************************/
	int getScorePlayer2(){ return m_scorePlayer2; }

	void incrementScorePlayer2()
	{
		m_scorePlayer2 = m_scorePlayer2++;
	}

	void setScorePlayer2(int score)
	{
		m_scorePlayer2 = score;
	}
	/**************************************************************/

private:

	const float m_SCALEplayer = 30.f;
	int m_scorePlayer1;
	int m_scorePlayer2;
};


#endif
