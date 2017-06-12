#pragma once
#ifndef BALL_H

#include<string>

class Ball
{
public:
	Ball(int x_position, int y_position, std::string texturePath)
		: m_x_Position(x_position), m_y_Position(y_position), m_texturePath(texturePath){}

	int getX_Position() {
		return m_x_Position;
	}

	int getY_Position() {
		return m_y_Position;
	}

	std::string getTexturePath() {
		return m_texturePath;
	}

private:
	int m_x_Position;
	int m_y_Position;

	std::string m_texturePath;
};


#endif // !PLAYER_H
