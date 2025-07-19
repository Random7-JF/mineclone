
#include "game.h"

bool Game::Init(int width, int height) {
  bool initialized = false;
  m_state.width = width;
  m_state.height = height;

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
                             "Error Initializing SDL3", nullptr);
    return initialized;
  }

  m_state.window = SDL_CreateWindow("SDL", m_state.width, m_state.height, 0);
  if (!m_state.window) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
                             "Error creating window", m_state.window);
    return initialized;
  }

  m_state.renderer = SDL_CreateRenderer(m_state.window, NULL);
  if (!m_state.renderer) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
                             "Error creating renderer", m_state.window);
    return initialized;
  }
  initialized = true;
  return initialized;
}

void Game::Run() {
  SDL_Log("running...");
  // start game loop
  bool running = true;
  while (running) {
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
    SDL_SetRenderDrawColor(m_state.renderer, 28, 20, 10, 255);
    SDL_RenderClear(m_state.renderer);

    // swap buffers
    SDL_RenderPresent(m_state.renderer);
  }
}

void Game::Cleanup() {
  SDL_DestroyWindow(m_state.window);
  SDL_Quit();
}
