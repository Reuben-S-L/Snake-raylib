#include "Fruit.h"
#include "raylib.h"


Fruit::Fruit()
{
	posX = GetRandomValue(0, 9);
	posY = GetRandomValue(0, 9);
	eaten = false;


}


int Fruit::getX()
{

	return posX;

}



int Fruit::getY()
{

	return posY;

}

bool Fruit::beenEaten()
{

	return eaten;

}

void Fruit::setEaten()
{

	eaten = true;

}