#include "Player.h"
using namespace std;

Player::Player()
{
	posX = 1;
	posY = 2;
	score = 0;
	speed.push_back(1);
	speed.push_back(0);

}


int  Player::getX()
{
	return posX;
}


int  Player::getY()
{
	return posY;
}

int Player::getScore()
{
	return score;
}

void Player::incrementScore(int a)
{
	score += a;
}

void Player::resetScore()
{
	score = 0;
}




void Player::updatePosition()
{

	posX += speed[0];
	posY += speed[1];
	

}

void Player::setPosition(int x, int y)
{
	posX = x;
	posY = y;
}

void Player::setDirection(char direction)
{



	if (direction == 'R' && speed[0] != -1)
	{
		speed[0] = 1; 
		speed[1] = 0;
	}
	if (direction == 'L' && speed[0] != 1)
	{
		speed[0] = -1; 
		speed[1] = 0;
	}
	if (direction == 'U' && speed[1] != 1)
	{
		speed[0] = 0; 
		speed[1] = -1;
	}
	if (direction == 'D' && speed[1] != -1)
	{
		speed[0] = 0; 
		speed[1] = 1;
	}

}