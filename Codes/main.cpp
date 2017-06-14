#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Window.h"

//=============================================================================================================================
//////	TEST-SFML!!		///////////
/*
int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
*/
//=====================================================================================================================


int main()
{

	////SFML erstellt einen Fenster mit Breite 800 x Länge 600 (Einheiten in Pixel) 
	//sf::RenderWindow window2(sf::VideoMode(800, 600), "Volleyball Game!");

	//window2.setFramerateLimit(60);
	//window2.setSize(sf::Vector2u(800 * 0.8, 600 * 0.8));


	///*while (window2.isOpen)
	//{
	//	if (event.type == sf::Event::Closed)
	//		window2.close();
	//}*/
	//window2.clear();
	//window2.display();


	Window Fenster(800, 600, "Test Fenster", 60);
	Player Spieler1(5, 1, true, "blobby.png");
	Player Spieler2(5, 1, true, "blobby.png");
	Player Spieler3(5, 1, true, "blobby.png");
	Player Spieler4(5, 1, true, "blobby.png");



	Fenster.closeWin();




	return 0;
}