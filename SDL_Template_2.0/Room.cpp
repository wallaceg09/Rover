#include "Room.h"
#include "Color.h"
#include "Constants.h"

//Room::Room(SDL_Rect rect)
//{
//	Room(rect, WHITE);
//}
//
//Room::Room(SDL_Rect rect, SDL_Color color)
//	: rectangle(rect), color(color)
//{
//}

Room::Room(int  x, int y, int width, int height) : Room(x, y, width, height, color)
{
}

Room::Room(int x, int y, int width, int height, const SDL_Color &color)
	:name(Text("Test", GREEN))
{
	int nWidth = width * ROOM_SIZE_INCREMENT;
	int nHeight = height * ROOM_SIZE_INCREMENT;
	this->rectangle = SDL_Rect{ x - (nWidth / 2), y - (nHeight / 2), nWidth, nHeight };
	this->color = color;
	this->center = SDL_Point{ x, y };
	renderCenterPoint = false;
}

Room::~Room()
{
}

void Room::render(Renderer &renderer)
{
	renderer.drawRect(this->rectangle, this->color);
	
	name.centerAt(this->center);
	name.render(renderer);

	if (this->renderCenterPoint)
	{
		renderer.drawPoint(this->center, WHITE);
	}
}

void Room::setColor(SDL_Color color)
{
	this->color = color;
}