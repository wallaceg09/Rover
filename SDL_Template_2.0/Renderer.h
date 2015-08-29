#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <map>
#include "Color.h"
#include <vector>
#include <string>

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

	void drawPolygon(int16_t * vx, int16_t * vy, int n, const SDL_Color &color);
	void drawPolygon(const std::vector<SDL_Point> &points, const SDL_Color &color);

	void fillPolygon(int16_t * vx, int16_t * vy, int n, const SDL_Color &color);
	void fillPolygon(const std::vector<SDL_Point> &points, const SDL_Color &color);

	void renderText(std::string text, const SDL_Point &point, const SDL_Color &color);
	void renderText(std::string text, const SDL_Point &point, const SDL_Color &color, float scale);
	void renderText(std::string text, const SDL_Point &point, const SDL_Color &color, float scaleX, float scaleY);

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

	void convertPointVectorToPolygonArrays(const std::vector<SDL_Point> points, int16_t *vx, int16_t *vy);
};

