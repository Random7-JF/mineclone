#pragma once
#include <SDL3/SDL.h>

struct SDLState {
  SDL_Window *window;
  SDL_Renderer *renderer;
  int width, height;
};

class Game {
private:
  SDLState m_state;

public:
  bool Init(int width, int height);
  void Cleanup();
  void Run();
};
