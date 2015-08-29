#pragma once
#include <string>
#include <SDL.h>
#include "Renderer.h"

class Text
{
public:
	Text(std::string value, SDL_Point position, const SDL_Color &color);
	Text(std::string value, const SDL_Color & color);
	~Text();

	void render(Renderer &renderer);
	void setValue(std::string value);

	void setColor(const SDL_Color &color);

	void centerAt(int x, int y);
	void centerAt(const SDL_Point &point);

	void setScaleX(float scaleX);
	void setScaleY(float scaleY);

	void setScale(float scale);
private:
	std::string value;
	SDL_Point position;
	SDL_Color color;
	float scaleX;
	float scaleY;
};

