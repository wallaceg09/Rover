#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <map>
#include "Color.h"

class Renderer
{
public:
	Renderer();
	~Renderer();
	bool initialized();
	SDL_Surface* loadSurface(std::string path);
	SDL_Renderer* getRenderer();
	void clear(const SDL_Color &color);
	void drawRect(const SDL_Rect &rect, const SDL_Color &color);
	void fillRect(const SDL_Rect &rect, const SDL_Color &color);
	void drawPoint(const SDL_Point &point, const SDL_Color &color);

	void update();

private:
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//Renderer for hardware accellerated rendering
	SDL_Renderer* renderer = NULL;

	//True if SDL initialization succeeded, false otherwise
	bool isInitialized = false;

	void init();
	void close();
	void printError(std::string formattedString);
	void setColor(const SDL_Color &color);

	
};

