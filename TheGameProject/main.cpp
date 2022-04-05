#include <iostream>
#include "Game.h"

int main() 
{
	//rand seed
	srand(static_cast<unsigned>(time(0)));

	//game object
	Game game;


	//game loop
	while (game.running())
	{
		game.update();
		game.render();
	}

	//end
	return 0;
}