#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "app.h"
#include "game.h"
int main(int argc, char *argv[]) {
  App app{};
  app.state.width = 1024;
  app.state.height = 768;

  Game game{&app.state};
  game.InitAndRun();
  app.CleanUp();
}
