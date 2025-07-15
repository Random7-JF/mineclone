#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "app.h"

int main(int argc, char *argv[])
{
	App app{};
	app.state.width = 1024;
	app.state.height = 768;

	if (!app.Initialize()){
		return 1;
	}

	// start game loop
	bool running =  true;
	while (running)
	{
		// start event loop
		SDL_Event event { 0 };
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_EVENT_QUIT:
				{
					running = false;
					break;
				}
			}
		}

		// draw calls
		SDL_SetRenderDrawColor(app.state.renderer,30,20,10,255);
		SDL_RenderClear(app.state.renderer);

		// swap buffers
		SDL_RenderPresent(app.state.renderer);

	}

	app.CleanUp();
	return 0;
}