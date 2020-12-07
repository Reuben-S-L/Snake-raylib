#include "Tail.h"

Tail::Tail(int X, int Y)
{

	posX = X;
	posY = Y;

}

int Tail::getX()
{
	return posX;
}

int Tail::getY()
{
	return posY;
}

void Tail::updatePosition(Tail tail)
{
	posX = tail.getX();
	posY = tail.getY();
}

void Tail::updatePosition(Player head)
{
	posX = head.getX();
	posY = head.getY();
}