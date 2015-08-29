#pragma once
#include <string>
#include <SDL.h>
#include "Renderer.h"

class Text
{
public:
	Text(std::string value, SDL_Point position);
	Text(std::string value);
	~Text();

	void render(Renderer &renderer, const SDL_Color &color);
	void setValue(std::string value);

	void centerAt(int x, int y);
	void centerAt(const SDL_Point &point);
private:
	std::string value;
	SDL_Point position;
	SDL_Color color;
};

