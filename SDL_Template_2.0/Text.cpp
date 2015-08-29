#include "Text.h"


Text::Text(std::string value, SDL_Point position)
{
	this->value = value;
	this->position = position;
}

Text::Text(std::string value) : Text(value, SDL_Point{ 0, 0 })
{
}

Text::~Text()
{
}

void Text::render(Renderer &renderer, const SDL_Color &color)
{
	renderer.renderText(this->value, this->position, color);
	printf("Rendering text at [%d, %d]\n", position.x, position.y);
}

void Text::centerAt(int x, int y)
{
	this->centerAt(SDL_Point{ x, y });
}

void Text::centerAt(const SDL_Point &point)
{
	int count = value.size();
	this->position.x = point.x - (count * 4);
	this->position.y = point.x - 4;
	printf("Centering text at [%d, %d]\n", point.x, point.y);
}
