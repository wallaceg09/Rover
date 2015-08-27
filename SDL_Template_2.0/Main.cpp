#include <SDL.h>
#include <stdio.h>
#include "Constants.h"
#include "Renderer.h"

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

	while(!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			/*SDL_SetRenderDrawColor(renderer.getRenderer(), 0x00, 0x00, 0x00, 0xFF);
			SDL_RenderClear(renderer.getRenderer());*/
			renderer.clear(BLACK);

			SDL_Rect drawRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
			renderer.drawRect(drawRect, WHITE);

			SDL_RenderPresent(renderer.getRenderer());
		}
	}

	return 0;
}