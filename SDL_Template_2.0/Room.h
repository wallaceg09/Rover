#pragma once
#include <SDL.h>

#include "Renderer.h"
#include "Text.h"
#include <string>

class Room
{
public:
	/*Room(SDL_Rect rect);
	Room(SDL_Rect rect, SDL_Color color);*/
	Room(int x, int y, int width, int height);
	Room(int x, int y, int width, int height, const SDL_Color &color);
	~Room();
	void render(Renderer &renderer);
	void setColor(SDL_Color color);

private:
	SDL_Rect rectangle;
	SDL_Color color;
	SDL_Point center;
	bool renderCenterPoint;

	Text name;
};

