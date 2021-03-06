#include "game.h"
#include "textureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "ECS.h"
#include "Components.h"




GameObject* player;
GameObject* enemy;
Map* map;


SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& newPlayer(manager.addEntity());

Game::Game()
{
}


Game::~Game()
{
}


void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "subsystems initialized" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window)
		{
			std::cout << "window created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer)
		{

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "rendere created" << std::endl;
		}

		isRunning = true;
	
	}else{
		isRunning = false;
	}

	player = new GameObject("assets/player.png", 0 , 0);
	enemy = new GameObject("assets/enemy.png", 50, 50);
	map = new Map();

	newPlayer.addComponent<PositionComponent>();
}


void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;


	default:
		break;
	}
}


void Game::update() {
	player->Update();
	enemy->Update();
	manager.update();

	std::cout << newPlayer.getComponent<PositionComponent>().x() << ", " <<
	newPlayer.getComponent<PositionComponent>().y() << std::endl;

}


void Game::render() {

	SDL_RenderClear(renderer);
	map->DrawMap();
	
	//add stuff to render
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);
}


void Game::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "game cleaned" << std::endl;
}


