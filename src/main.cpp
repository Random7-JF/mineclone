#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "game.h"

int main(int argc, char *argv[]) {
  int width = 1280;
  int height = 720;
  int game_width = 640;
  int game_height = 360;

  Game game;
  if (!game.Init(width, height, game_width, game_height)) {
    SDL_Log("Failed to Init");
  }
  game.Run();
  game.Cleanup();
}
