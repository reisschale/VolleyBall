/*********************************************************************
Modul:		Softwaretechnik
Dozent:		Prof. Dr. Thomas Baar
Autoren:	Tuan Anh Le (550445)
		Ali Sahin(554161)
		Max Ruhnau (543826)
Semester:	2016/17
**********************************************************************
Quelltext:	Канал пользователя FamTrinli (YouTube)
Link:		https://www.youtube.com/watch?v=g9iQ6M1QKIU&t=22s
**********************************************************************/

//=====================================================================================================================
////_____VOLLEYBALL CODE______////

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "WorldGlobal.h"
#include "Player.h"
#include "Ball.h"
#include "MyContactListener.h"
#include <SFML/Graphics/Font.hpp>
#include <sstream>
#include <iostream>

//using namespace sf;
const float SCALE = 30.f;
const float DEG = 57.29577f;
MyContactListener ContactInstance;



int main()
{
	/***PUNKTESTAND PartI: SFML-Konfig****************************************/

	sf::Font fontRobot;
	fontRobot.loadFromFile("fonts/Roboto-Bold.ttf");

	sf::Text Punktestand;
	Punktestand.setFont(fontRobot);
	//Punktestand1.setString("Hello World!");
	Punktestand.setCharacterSize(48);
	Punktestand.setFillColor(sf::Color::Green);
	
	/*************************************************************************/

	//SFML erstellt einen Fenster mit Breite 800 x Länge 600 (Einheiten in Pixel) 
	sf::RenderWindow window(sf::VideoMode(800, 600), "Volleyball Game!");
	
	window.setFramerateLimit(60);
	window.setSize(sf::Vector2u(800 * 0.8, 600 * 0.8));

	//**Import_Backgroundpictures**********************//
	//Klasse Texture aus SFML
	sf::Texture t1, t2, t3;
	t1.loadFromFile("images/background.png");
	t2.loadFromFile("images/ball.png");
	t3.loadFromFile("images/blobby.png");
	t1.setSmooth(true);
	t2.setSmooth(true);
	t3.setSmooth(true);

	//Kontruktor: Sprite(Texture)
	sf::Sprite sBackground(t1), sBall(t2), sPlayer(t3);
	sPlayer.setOrigin(75 / 2, 90 / 2);
	sBall.setOrigin(32, 32);
	//************************************************//
	

	//**BOX2D****************************************//
	//Aus der Klasse WorldGlobal wird ein Objekt
	//names "Spielwand" erstellt
	

	//Objekt mit den verschiedenen Parametern
	//Einheiten sind in Meter angeben

	WorldGlobal Spielwand1(400, 520, 2000, 10, false);
	//Spielwand1.initWall();
	WorldGlobal Netzwand(400, 450, 10, 170, false);
	//Netzwand.initWall();
	WorldGlobal linkeWand(0, 0, 10, 2000, false);
	//linkeWand.initWall();
	WorldGlobal rechteWand(800, 0, 10, 2000, false);
	//rechteWand.initWall();
	//************************************************/


	/**PLAYERS_aus_Header*******************************/
	shape.SetAsBox(30 / SCALE, 30 / SCALE); 
	bdef.type = b2_dynamicBody;

	Player Spieler(2);

	Spieler.initPlayerName();
	//**************************************************/

	

	/**BALL_aus_Header***********************************/
	Ball Spielball(32, false);
	Spielball.counting();
	/*****************************************************/
	MyContactListener ContactInstance;
	World.SetContactListener(&ContactInstance);

	
	bool onGround = 0;

	while (window.isOpen())
	{
		

		//Event lässt das Fenster bewegen
		sf::Event e;
		
		//mit dieser Funktion kann man nun das Fenster schließen
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}



		for (int n = 0; n<2; n++) // 2 - speed
			World.Step(1 / 60.f, 8, 3);

		//**Player_1**************************************************************************// 
		pos = pBody[0]->GetPosition();
		vel = pBody[0]->GetLinearVelocity();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))	vel.x = 5; 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))	vel.x = -5;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))    if (pos.y*SCALE >= 463)  vel.y = -11;

		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				vel.x = 0;

		pBody[0]->SetLinearVelocity(vel);
		//*************************************************************************************//



		//**Player_2***************************************************************************//
		pos = pBody[1]->GetPosition();
		vel = pBody[1]->GetLinearVelocity();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))  vel.x = 5;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  vel.x = -5;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    if (pos.y*SCALE >= 463)  vel.y = -11;

		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				vel.x = 0;

		pBody[1]->SetLinearVelocity(vel);
		//**************************************************************************************//

		//Ballgeschwindigkeit
		Spielball.initSpeed();
		

		//////////Draw///////////////
		window.draw(sBackground);

		for (b2Body* it = World.GetBodyList(); it != 0; it = it->GetNext())
		{
			b2Vec2 pos = it->GetPosition();
			float angle = it->GetAngle();

			if (it->GetUserData() == "player1")
			{
				sPlayer.setPosition(pos.x*SCALE, pos.y*SCALE);
				sPlayer.setRotation(angle*DEG);
				sPlayer.setColor(sf::Color::Red);
				window.draw(sPlayer);
			}

			if (it->GetUserData() == "player2")
			{
				sPlayer.setPosition(pos.x*SCALE, pos.y*SCALE);
				sPlayer.setRotation(angle*DEG);
				sPlayer.setColor(sf::Color::Green);
				window.draw(sPlayer);
			}

			if (it->GetUserData() == "ball")
			{
				sBall.setPosition(pos.x*SCALE, pos.y*SCALE);
				sBall.setRotation(angle*DEG);
				window.draw(sBall);
			}
		}

		

		/***PUNKTESTAND PART II: Punktestand einblenden und zählen********************/

		//Punktestand für beide Spieler
		//Konvertierung int in string
		std::stringstream ss;
		ss << Spieler.getScorePlayer1() << " : " << Spieler.getScorePlayer2();

		std::string Score = ss.str();
		Punktestand.setString(Score);
		/*******************************************************************************/

		
		window.draw(Punktestand);
		window.display();

	}
	
	//Punktestandausgabe-Test
	//std::cout << Spieler.getScorePlayer1() << std::endl;
	//std::cout << Spieler.getScorePlayer2() << std::endl;


	return 0;
}
//=============================================================================================================================





//=============================================================================================================================
////////	TEST-SFML!!		///////////
//
//#include <SFML/Graphics.hpp>
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//	sf::CircleShape shape(100.f);
//	shape.setFillColor(sf::Color::Green);
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		window.clear();
//		window.draw(shape);
//		window.display();
//	}
//
//	return 0;
//}
//=====================================================================================================================
