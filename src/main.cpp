#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

void cleanup(SDL_Window *window);

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	int width = 800;
	int height = 600;
	SDL_Window *window = SDL_CreateWindow("SDL", width, height, 0);
	if (!window) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error creating window", window);
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

	}

	cleanup(window);
	return 0;
}

void cleanup(SDL_Window *window) {
	SDL_DestroyWindow(window);
	SDL_Quit();
}