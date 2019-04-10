#include "GameObject.h"
#include "textureManager.h"



GameObject::GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y)
{
	renderer = ren;
	objTexture = TextureManager::loadTexture(textureSheet, ren);
	xpos = x;
	ypos = y;

}


GameObject::~GameObject()
{
}


void GameObject::Update() {

	xpos++;
	ypos++;


	srcRect.h = 1854;
	srcRect.w = 1473;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = 80;
	destRect.w = 64;


}


void GameObject::Render() {

	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);

}
