#pragma once
#include "Player.h"

class Tail
{

	public:

		Tail(int X, int Y);
		int getX();
		int getY();
		void updatePosition(Tail tail);
		void updatePosition(Player head);

	private:
		int posX;
		int posY;
		

};