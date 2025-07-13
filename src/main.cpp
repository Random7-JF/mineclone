#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>

SDL_Window* window;
SDL_Renderer* renderer;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {
	if(!(SDL_Init(SDL_INIT_VIDEO))) {
		SDL_Log("error initializing SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	window = SDL_CreateWindow(
		"Mineclone",
		800,
		600,
		SDL_WINDOW_RESIZABLE);
	if(!window) {
		SDL_Log("error initializing SDL Window: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	renderer = SDL_CreateRenderer(window, NULL);
	if(!window) {
		SDL_Log("error initializing SDL Renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	return SDL_APP_CONTINUE;
} 

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
	SDL_Log("Closing App.");
	
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_QuitSubSystem(SDL_INIT_VIDEO);

}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
	if (event->type == SDL_EVENT_QUIT) {
		return SDL_APP_SUCCESS;
	}

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
	//SDL_Log("tick");
	return SDL_APP_CONTINUE;
}