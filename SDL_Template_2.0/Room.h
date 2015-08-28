#pragma once
#include <SDL.h>

#include "Renderer.h"
class Room
{
public:
	Room(SDL_Rect rect);
	Room(SDL_Rect rect, SDL_Color color);
	Room(float x, float y, float width, float height);
	Room(float x, float y, float width, float height, SDL_Color color);
	~Room();
	void render(Renderer &renderer);
	void setColor(SDL_Color color);

private:
	SDL_Rect rectangle;
	SDL_Color color;
};

