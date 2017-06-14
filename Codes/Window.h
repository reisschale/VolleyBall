#pragma once
#ifndef WINDOW_H

#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
#include <iostream>
#include "Ball.h"
#include "Player.h"

class Window
{
public:
	Window(int width, int length, std::string title, int frameLimit);

	void setTexturePath(std::string texturePath) {
		m_shape.loadFromFile(texturePath);
	}


	
	void createTexture();

	void closeWin();

private:
	sf::RenderWindow m_window;

	sf::Texture m_shape;
	int m_width;
	int m_length;
	std::string m_windowTitle;
	int m_Frame;
	static int s_numInstances;
	std::string s_currentName;

};
#endif // !WINDOW_H

