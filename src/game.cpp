
#include "game.h"
#include "app.h"

bool Game::InitAndRun() {
  if (m_AppState != nullptr) {
    Run();
  }
  return false;
}

bool Game::Run() {
  SDL_Log("running...");
  // start game loop
  bool running = true;
  while (running) {
    SDL_Log("tick");
    // start event loop
    SDL_Event event{};
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_EVENT_QUIT: {
        running = false;
        break;
      }
      }
    }

    // draw calls
    SDL_SetRenderDrawColor(m_AppState->renderer, 28, 20, 10, 255);
    SDL_RenderClear(m_AppState->renderer);

    // swap buffers
    SDL_RenderPresent(m_AppState->renderer);
  }
  return running;
}
