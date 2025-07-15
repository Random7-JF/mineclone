#include "app.h"

bool App::Initialize()
{
	bool initialized = false;
	if(!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error Initializing SDL3", nullptr);
		return initialized;
	}

	state.window = SDL_CreateWindow("SDL", state.width, state.height, 0);
	if (!state.window) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error creating window", state.window);
		return initialized;
	}

	state.renderer = SDL_CreateRenderer(state.window, NULL);
	if (!state.renderer) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error creating renderer", state.window);
		return initialized;
	}
	initialized = true;
	return initialized;
}

void App::CleanUp()
{
	SDL_DestroyWindow(state.window);
	SDL_Quit();
}
