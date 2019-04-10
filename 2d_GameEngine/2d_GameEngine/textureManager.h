#pragma once


#include"Game.h"


class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	static SDL_Texture* loadTexture(const char* filename, SDL_Renderer* ren);


private:

};
