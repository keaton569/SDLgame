#include "SDL.h"
#include "game.h"
#undef main


Game* game = nullptr;

int main(int argc, const char * argv[]) {
	
	game = new Game();


	game->init("engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->isRunning)
	{
		game->handleEvents();
		game->update();
		game->render();
	}


	game->clean();
	return 0;
}