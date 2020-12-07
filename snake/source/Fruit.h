#pragma once

class Fruit
{
	public:

	Fruit();

	
	int getX();
	int getY();
	bool beenEaten();
	void setEaten();


	private:

		int posX;
		int posY;
		bool eaten;


};