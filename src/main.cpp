#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "game.h"

int main(int argc, char *argv[]) {
  int width = 1024;
  int height = 769;

  Game game;
  if (!game.Init(height, width)) {
    SDL_Log("Failed to Init");
  }
  game.Run();
  game.Cleanup();
}
