#include "Text.h"


Text::Text(std::string value, SDL_Point position, const SDL_Color &color)
{
	this->value = value;
	this->position = position;
	this->color = color;
	this->setScale(1.0);
}

Text::Text(std::string value, const SDL_Color &color) : Text(value, SDL_Point{ 0, 0 }, color)
{
}

Text::~Text()
{
}

void Text::render(Renderer &renderer)
{
	renderer.renderText(this->value, this->position, this->color, this->scaleX, this->scaleY);
	printf("Rendering text at [%d, %d]\n", position.x, position.y);
}

void Text::setValue(std::string value)
{
	this->value = value;
}

void Text::setColor(const SDL_Color &color)
{
	this->color = color;
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

//FIXME: Scaling is causing the centering method to work incorrectly
void Text::setScaleX(float scaleX)
{
	this->scaleX = scaleX;
}

//FIXME: Scaling is causing the centering method to work incorrectly
void Text::setScaleY(float scaleY)
{
	this->scaleY = scaleY;
}

//FIXME: Scaling is causing the centering method to work incorrectly
void Text::setScale(float scale)
{
	this->setScaleX(scale);
	this->setScaleY(scale);
}