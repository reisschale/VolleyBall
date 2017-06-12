#pragma once
#ifndef WINDOW_H

#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
#include "Ball.h"
#include "Player.h"

class Window
{
public:
	Window(int width, int length, std::string title, int frameLimit) 
		: m_width(width), m_length(length), m_windowTitle(title),  m_Frame(frameLimit)
	{
		//m_window.sf::VideoMode((m_width, m_length), m_windowTitle);
		//m_window.setFramerateLimit(frameLimit);
		//m_window.setSize(sf::Vector2u(800 * 0.8, 600 * 0.8));
	}

	void setTexturePath(std::string texturePath) {
		m_shape.loadFromFile(texturePath);
	}

private:
	sf::RenderWindow m_window;

	sf::Texture m_shape;
	int m_width;
	int m_length;
	std::string m_windowTitle;
	int m_Frame;



};
#endif // !WINDOW_H

