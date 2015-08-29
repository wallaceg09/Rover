#include <SDL.h>
#include <stdio.h>

#include "Constants.h"
#include "Renderer.h"
#include "Room.h"

int main(int argc, char* args[])
{
	Renderer renderer;
	if (!renderer.initialized())
	{
		printf("Renderer could not be initialized! Ending process.");
		SDL_Delay(5000);
		return 1;
	}

	bool quit = false;

	SDL_Event e;

	Room testRoom(150, 150, 3, 2, GREEN);

	while(!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			renderer.clear(BLACK);

			//testRoom.render(renderer);

			//Test Polygon
			std::vector<SDL_Point> points;
			points.push_back(SDL_Point{ 150, 150 });
			points.push_back(SDL_Point{ 130, 120 });
			points.push_back(SDL_Point{ 150, 90 });
			points.push_back(SDL_Point{ 170, 120 });

			renderer.drawPolygon(points, RED);
			
			renderer.update();
		}
	}

	return 0;
}