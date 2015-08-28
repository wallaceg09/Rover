#include "Renderer.h"

#include "Constants.h"

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