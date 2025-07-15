#pragma once
#include <SDL3/SDL.h>

struct AppState
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	int width, height;
};

class App {
	private:

	public:
		AppState state;
		bool Initialize();
		void CleanUp();	

};