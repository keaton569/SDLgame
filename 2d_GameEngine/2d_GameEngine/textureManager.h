#pragma once


#include"Game.h"


class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	static SDL_Texture* loadTexture(const char* filename);
	static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);

private:

};
