#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

struct SDLState
{
	SDL_Window *window;
	SDL_Renderer *renderer;
};

void cleanup(SDLState &state);

int main(int argc, char *argv[])
{
	SDLState state;

	if(!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error Initializing SDL3", nullptr);
		return 1;
	}

	int width = 1024;
	int height = 768;
	state.window = SDL_CreateWindow("SDL", width, height, 0);
	if (!state.window) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error creating window", state.window);
		return 1;
	}

	state.renderer = SDL_CreateRenderer(state.window, NULL);
	if (!state.renderer) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error creating renderer", state.window);
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
		SDL_SetRenderDrawColor(state.renderer,30,20,10,255);
		SDL_RenderClear(state.renderer);

		// swap buffers
		SDL_RenderPresent(state.renderer);

	}

	cleanup(state);
	return 0;
}

void cleanup(SDLState &state) {
	SDL_DestroyWindow(state.window);
	SDL_Quit();
}