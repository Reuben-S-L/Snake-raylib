#pragma once
#include <vector>

using namespace std;

class Player
{
public:

	Player();

	int getX();
	int getY();
	int getScore();
	void incrementScore(int a);
	void resetScore();
	void setPosition(int x, int y);
	void updatePosition();
	void setDirection(char direction);



private:

	int posX;
	int posY;
	vector<int> speed;
	int score = 0;


};