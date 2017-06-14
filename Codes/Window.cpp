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

	sf::Texture t1, t2, t3;
	t1.loadFromFile("images/background.png");
	t2.loadFromFile("images/ball.png");
	t3.loadFromFile("images/blobby.png");

	sf::Sprite sBackground(t1), sBall(t2), sPlayer(t3);
	sPlayer.setOrigin(75 / 2, 90 / 2);
	sBall.setOrigin(32, 32);

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

		

			m_window.draw(sBackground);
			m_window.draw(sPlayer);
			m_window.draw(sPlayer);
			m_window.draw(sBall);
			

		

		}
	}


};
//----------------------------------------------------------------------------------------------------------------------

////Referenz zur Klasse Player im Parameter - Es werden MAXIMAL 4 Spieler erzeugt
//void Window::createPTexture(Player& rPlayer)
//{
//	//3 Stellen werden erzeugt und mit 0 gefüllt, abgesehen von numInstances
//	/*std::stringstream ss;
//	ss << "Texture_" << std::setw(3) << std::setfill('0') << s_numInstances;
//	s_currentName = ss.str();*/
//
//	if (s_numInstances == 1) {
//
//		//Objekt Texture wird erzeugt
//		sf::Texture T1;
//		T1.loadFromFile(rPlayer.getTexturePath());
//		T1.setSmooth(true);
//
//	}
//
//	if (s_numInstances == 2) {
//
//		sf::Texture T2;
//		T2.loadFromFile(rPlayer.getTexturePath());
//		T2.setSmooth(true);
//	}
//
//	if (s_numInstances == 3) {
//
//		sf::Texture T3;
//		T3.loadFromFile(rPlayer.getTexturePath());
//		T3.setSmooth(true);
//	}
//
//	if (s_numInstances == 4) {
//
//		sf::Texture T4;
//		T4.loadFromFile(rPlayer.getTexturePath());
//		T4.setSmooth(true);
//	}
//
//
//	//Zähler wird hochgezählt
//	s_numInstances++;
//}

void Window::createTexture() {
	sf::Texture t1, t2, t3;
	t1.loadFromFile("images/background.png");
	t2.loadFromFile("images/ball.png");
	t3.loadFromFile("images/blobby.png");

	sf::Sprite sBackground(t1), sBall(t2), sPlayer(t3);
		sPlayer.setOrigin(75 / 2, 90 / 2);
		sBall.setOrigin(32, 32);

		m_window.draw(sBackground);
		m_window.draw(sPlayer);
		m_window.draw(sPlayer);
		m_window.draw(sBall);
}


//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------

void Window::closeWin() {
	m_window.clear();
	m_window.display();
}

//----------------------------------------------------------------------------------------------------------------------
