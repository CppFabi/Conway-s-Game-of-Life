// O------------------------------------------------------------------------------O
// | Example "Hello World" Program (main.cpp)                                     |
// O------------------------------------------------------------------------------O

#define OLC_PGE_APPLICATION
#include "GameOfLife.h"

int main()
{
	GameOfLife game;
	if (game.Construct(80, 45, 20, 20))
		game.Start();
	return 0;
}
