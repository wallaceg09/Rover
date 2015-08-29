#include "Renderer.h"

#include "Constants.h"
#include "SDL2_gfxPrimitives.h"
#include <memory>

#pragma region public
Renderer::Renderer()
{
	init();
}


Renderer::~Renderer()
{
	close();
}

bool Renderer::initialized()
{
	return this->isInitialized;
}


SDL_Renderer* Renderer::getRenderer()
{
	return this->renderer;
}

void Renderer::clear(const SDL_Color &color)
{
	this->setColor(color);
	SDL_RenderClear(this->renderer);
}

void Renderer::drawRect(const SDL_Rect &rect, const SDL_Color &color)
{
	this->setColor(color);
	SDL_RenderDrawRect(this->renderer, &rect);
}

void Renderer::fillRect(const SDL_Rect &rect, const SDL_Color &color)
{
	this->setColor(color);
	SDL_RenderFillRect(this->renderer, &rect);
}

void Renderer::drawPoint(const SDL_Point &point, const SDL_Color &color)
{
	this->setColor(color);
	SDL_RenderDrawPoint(this->renderer, point.x, point.y);
}

void Renderer::drawPolygon(int16_t * vx, int16_t * vy, int n, const SDL_Color &color)
{
	polygonRGBA(this->renderer, vx, vy, n, color.r, color.g, color.b, color.a);
}

void Renderer::drawPolygon(const std::vector<SDL_Point> &points, const SDL_Color &color)
{
	int n = points.size();
	std::unique_ptr<int16_t[]> vx(new int16_t[n]);
	std::unique_ptr<int16_t[]> vy(new int16_t[n]);
	convertPointVectorToPolygonArrays(points, vx.get(), vy.get());

	drawPolygon(vx.get(), vy.get(), n, color);
}

void Renderer::fillPolygon(int16_t * vx, int16_t * vy, int n, const SDL_Color &color)
{
	filledPolygonRGBA(this->renderer, vx, vy, n, color.r, color.g, color.b, color.a);
}

void Renderer::fillPolygon(const std::vector<SDL_Point> &points, const SDL_Color &color)
{
	int n = points.size();
	std::unique_ptr<int16_t[]> vx(new int16_t[n]);
	std::unique_ptr<int16_t[]> vy(new int16_t[n]);

	convertPointVectorToPolygonArrays(points, vx.get(), vy.get());

	fillPolygon(vx.get(), vy.get(), n, color);
}

void Renderer::convertPointVectorToPolygonArrays(const std::vector<SDL_Point> points, int16_t *vx, int16_t *vy)
{
	int n = points.size();
	for (int i = 0; i < n; ++i)
	{
		const SDL_Point* currentPoint = &points.at(i);
		vx[i] = static_cast<int16_t>(currentPoint->x);
		vy[i] = static_cast<int16_t>(currentPoint->y);
	}
}

void Renderer::update()
{
	SDL_RenderPresent(this->renderer);
}

#pragma endregion

#pragma region private
void Renderer::init()
{
	isInitialized = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_FLAGS) < 0)
	{
		printError("SDL could not initialize!");
		isInitialized = false;
		return;
	}

	//Create window
	this->window = SDL_CreateWindow("SDL 2.0 Template", SCREEN_POSITION_X, SCREEN_POSITION_Y, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_WINDOW_FLAGS);

	if (window == NULL)
	{
		printError("Window could not be created!");
		isInitialized = false;
		return;
	}

	//Initialize renderer
	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

	if (this->renderer == NULL)
	{
		printf("SDL_renderer could not be initialized! SDL Error: %s", SDL_GetError());
		isInitialized = false;
		return;
	}

	//Clear screen
	setColor(BLACK);
	SDL_RenderClear(renderer);
}

void Renderer::close()
{
	//Destroy window
	SDL_DestroyWindow(this->window);
	window = NULL;

	//Destroy renderer
	SDL_DestroyRenderer(this->renderer);
	renderer = NULL;

	//Quit SDL
	SDL_Quit();
}

void Renderer::printError(std::string formattedString)
{
	printf("%s SDL Error: %s\n", formattedString.c_str(), SDL_GetError());
}

void Renderer::setColor(const SDL_Color &color)
{
	SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, color.a);
}

#pragma endregion