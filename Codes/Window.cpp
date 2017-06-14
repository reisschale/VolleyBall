#include "Window.h"
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>

int Window::s_numInstances = 1;

//----------------------------------------------------------------------------------------------------------------------
//Konstruktor
Window::Window(int width, int length, std::string title, int frameLimit)
	: m_width(width), m_length(length), m_windowTitle(title), m_Frame(frameLimit)
{
	//Konfiguration für das Fenster 800 Breite x 600 Länge
	Window::m_window.create(sf::VideoMode(m_width, m_length), m_windowTitle);
	m_window.setFramerateLimit(frameLimit);
	m_window.setSize(sf::Vector2u(m_width * 0.8, m_length * 0.8));

	while (m_window.isOpen())
	{
		//Event lässt das Fenster bewegen
		sf::Event moveWin;
		while (m_window.pollEvent(moveWin))
		{
			if (moveWin.type == sf::Event::Closed)
			{
				m_window.close();
			}

		}
	}


};
//----------------------------------------------------------------------------------------------------------------------

void Window::createTexture()
{
	//3 Stellen werden erzeugt und mit 0 gefüllt, abgesehen von numInstances
	std::stringstream ss;
	ss << "Texture_" << std::setw(3) << std::setfill('0') << s_numInstances;
	s_currentName = ss.str();

	//Objekt Texture wird erzeugt
	sf::Texture s_currentName;

	// Erstellt kurzeit ein Objekt Spieler damit man auf die "getTexturePath" der Player-Klasse zugreifen kann
	Player *currentPlayer = new Player;
	//std::cout << currentPlayer->getTexturePath() << std::endl;


	s_currentName.loadFromFile(currentPlayer->getTexturePath());

	
	delete currentPlayer;
	s_numInstances++;
}

//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------

void Window::closeWin() {
	m_window.clear();
	m_window.display();
}

//----------------------------------------------------------------------------------------------------------------------
