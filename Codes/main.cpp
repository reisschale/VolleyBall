#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

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

	//SFML erstellt einen Fenster mit Breite 800 x Länge 600 (Einheiten in Pixel) 
	sf::RenderWindow window(sf::VideoMode(800, 600), "Volleyball Game!");

	window.setFramerateLimit(60);
	window.setSize(sf::Vector2u(800 * 0.8, 600 * 0.8));


	while (window.isOpen)
	{
	}
	window.clear();
	window.display();

	return 0;
}