#include "Room.h"
#include "Color.h"

//Room::Room(SDL_Rect rect)
//{
//	Room(rect, WHITE);
//}
//
//Room::Room(SDL_Rect rect, SDL_Color color)
//	: rectangle(rect), color(color)
//{
//}

Room::Room(float x, float y, float width, float height)
{
	Room(x, y, width, height, WHITE);
}

Room::Room(float x, float y, float width, float height, SDL_Color color)
{
	this->rectangle = SDL_Rect{ x, y, width, height };
	this->color = color;
}

Room::~Room()
{
}

void Room::render(Renderer &renderer)
{
	renderer.drawRect(this->rectangle, WHITE);
}

void Room::setColor(SDL_Color color)
{
	this->color = color;
}