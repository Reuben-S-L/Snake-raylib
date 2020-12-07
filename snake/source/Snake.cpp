#include "raylib.h"
#include <string>
#include <list>
#include "Player.h"
#include "Fruit.h"
#include "Tail.h"

using namespace std;

int main()
{
	const int WindowWidth = 1280;
	const int WindowHeight = 720;
	float timeSinceLastPositionUpdate = 0;
	float refreshTime = 0.5f;
	Fruit fruit = Fruit();
	vector<Tail> tail = vector<Tail> {}; 
	bool gameOver = false;
	
	

	Player player;


	InitWindow(WindowWidth, WindowHeight, "SNAKE");

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(GOLD);


	
		
		

		//CREATING VARIABLES NEEDED TO DRAW AND NAME SECTIONS OF THE GRID

		int gridPosX = 275;
		int gridPosY = 20;
		int indexX = 1;
		int indexY = 1;

		//INCREMENT TIME COUNTER SO SNAKE KNOWS WHEN TO UPDATE ITS POSITION

		timeSinceLastPositionUpdate += GetFrameTime();

		bool tileIsTail = false;


		//DISPLAY CURRENT SCORE
		
		DrawText(FormatText("SCORE: %i", player.getScore()), 10, 10, 30, GRAY);
		
		
		if (gameOver == false)
		{
			

			for (int j = 0; j < 10; j++)
			{


				for (int i = 0; i < 10; i++)
				{
					vector<Tail>::iterator it;

					//CHECKS WHETHER THE TILE CURRENTLY BEING DRAWN IS A TAIL SECTION OR NOT

					for (it = tail.begin(); it != tail.end(); ++it)
					{


						if (it->getX() == i && it->getY() == j)
						{

							tileIsTail = true;

						}
						


					}

					//DARWS TAIL IF CURRENT TILE IS A SECTION OF THE TAIL

					if (tileIsTail)
					{

						DrawRectangle(gridPosX, gridPosY, WindowHeight / 11, WindowHeight / 11, Color{ 230, 41, 55, 200 });

						gridPosX += ((WindowHeight / 11) + 2);

						indexX++;

						tileIsTail = false;

					}
					else

						//CHECKS IF CURRENT TILE IS THE PLAYER POSITION AND DRAWS THE PLAYER IF TRUE

						if (player.getX() == i && player.getY() == j)
						{
							DrawRectangle(gridPosX, gridPosY, WindowHeight / 11, WindowHeight / 11, RED);

							gridPosX += ((WindowHeight / 11) + 2);

							indexX++;


						}
						else

							//CHECKS IF CURRENT TILE IS THE FRUITS POSITION AND DRAWS THE FRUIT IF TRUE

							if (fruit.getX() == i && fruit.getY() == j)
							{

								DrawRectangle(gridPosX, gridPosY, WindowHeight / 11, WindowHeight / 11, DARKGREEN);

								gridPosX += ((WindowHeight / 11) + 2);

								indexX++;

							}

							//IF NONE OF THE ABOVE ARE TRUE, DEFAULTS TO DRAWING A GREY TILE AS PART OF THE GRID

							else
							{

								DrawRectangle(gridPosX, gridPosY, WindowHeight / 11, WindowHeight / 11, GRAY);

								gridPosX += ((WindowHeight / 11) + 2);

								indexX++;
							}

				}

				//RESETS X POSITON AND MOVES Y DOWN SO A NEW ROW OF THE GRID CAN BE DRAWN

				gridPosY += (WindowHeight / 11 + 2);
				gridPosX = 275;

				indexY++;
			}

			//ADDS A NEW SECTION TO THE TAIL IF THE PLAYER COLLECTS A FRUIT AND SPAWNS ANOTHER FRUIT

			if (player.getX() == fruit.getX() && player.getY() == fruit.getY())
			{

				Tail tailSection = Tail(fruit.getX(), fruit.getY()); 
				tail.insert(tail.begin(), tailSection);
				//tail.push_back(tailSection);
				player.incrementScore(1);
				fruit = Fruit();

				if (tail.size() % 5 == 0)
				{
					refreshTime -= 0.08;
				}

				

			}



			//RECIEVES USER INPUT, SETTING PLAYERS DIRECTION OF TRAVEL

			if (IsKeyPressed(KEY_RIGHT)) player.setDirection('R');
			if (IsKeyPressed(KEY_LEFT)) player.setDirection('L');
			if (IsKeyPressed(KEY_UP)) player.setDirection('U');
			if (IsKeyPressed(KEY_DOWN)) player.setDirection('D');

			//UPDATES THE TAIL AND PLAYERS POSITION AFTER 0.5 SECONDS HAVE PASSED

			if (timeSinceLastPositionUpdate > refreshTime)
			{

				if (tail.size() > 1)
				{			
					for (int i = 2; i < tail.size(); i++)
					{
						if (tail[i].getX() == player.getX() && tail[i].getY() == player.getY())
						{
							gameOver = true;
						}
					}

					for (int i = tail.size(); i > 1; i--)
					{
						tail[i - 1].updatePosition(tail[(i - 2)]);	
																
					}

					
				}

				//CHECKS FOR PLAYER BEING OUT OF BOUNDS AND SETS GAME OVER IF TRUE

				if (player.getX() > 9 || player.getY() > 9 || player.getX() < 0 || player.getY() < 0)
				{
					gameOver = true;
				}

				if (tail.size() > 0)
				{
					tail[0].updatePosition(player);

				}


				player.updatePosition();

				timeSinceLastPositionUpdate = 0;
			}
		}

		//IF GAME OVER = TRUE, GAME OVER SCREEN IS DISPLAYED. LEFT CLICK RESTARTS THE GAME

		else
		{
			DrawText("GAME OVER", (WindowWidth/2)-100, WindowHeight/2, 30, GRAY);
			DrawText("left click to restart", (WindowWidth / 2) - 100, (WindowHeight / 2)+25, 20, GRAY);
			
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{

				tail.clear();
				player.resetScore();
				player.setPosition(4, 4);
				refreshTime = 0.5f;
				


				gameOver = false;

			}
		}



		EndDrawing();

		
	}

	

}


