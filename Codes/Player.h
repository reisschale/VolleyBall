#pragma once
#ifndef PLAYER_H

#include<string>

class Player
{
public:

	Player(){}
	Player(int x_position, int y_position, bool side, std::string texturePath)
		: m_x_Position(x_position), m_y_Position(y_position), m_side(side) , m_Points(0), m_texturePath(texturePath) {}

	std::string getTexturePath() {
		return m_texturePath;
	}

	int getX_Position() {
		return m_x_Position;
	}

	int getY_Position() {
		return m_y_Position;
	}

	void incrementPoints() {
		m_Points++;
	}

	int getPoints() {
		return m_Points;
	}

	bool getSide(){
		return m_side;
	}

private:
	int m_x_Position;
	int m_y_Position;
	
	bool m_side;

	int m_Points;

	std::string m_texturePath;
};


#endif // !PLAYER_H
