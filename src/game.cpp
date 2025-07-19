#include <SDL3_image/SDL_image.h>

#include "game.h"

bool Game::Init(int width, int height, int game_width, int game_height) {
  bool initialized = false;
  m_state.width = width;
  m_state.height = height;
  m_state.game_width = game_width;
  m_state.game_height = game_height;

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
                             "Error Initializing SDL3", nullptr);
    return initialized;
  }

  m_state.window = SDL_CreateWindow("SDL", m_state.width, m_state.height, SDL_WINDOW_RESIZABLE);
  if (!m_state.window) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
                             "Error creating window", m_state.window);
    return initialized;
  }

  m_state.renderer = SDL_CreateRenderer(m_state.window, NULL);
  if (!m_state.renderer) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
                             "error creating renderer", m_state.window);
    return initialized;
  }
  initialized = true;
  return initialized;
}

void Game::Run() {
  SDL_Log("running...");
  //config game presentation
  SDL_SetRenderLogicalPresentation(m_state.renderer, m_state.game_width, m_state.game_height, SDL_LOGICAL_PRESENTATION_INTEGER_SCALE);
  // load game assests
  SDL_Texture *idleTex = IMG_LoadTexture(m_state.renderer, "data/idle.png");
  SDL_SetTextureScaleMode(idleTex, SDL_SCALEMODE_NEAREST);
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
      case SDL_EVENT_WINDOW_RESIZED:
      {
        m_state.width = event.window.data1;
        m_state.height = event.window.data2;
        break;
      }
      }
    }

    // draw calls
    SDL_SetRenderDrawColor(m_state.renderer, 28, 20, 10, 255);
    SDL_RenderClear(m_state.renderer);

    SDL_FRect src {
      .x = 32*22,
      .y = 32,
      .w = 32,
      .h = 32
    };
    
    SDL_FRect dst {
      .x = m_state.game_width/2-32,
      .y = m_state.game_height/2-32,
      .w = 64,
      .h = 64
    };

    SDL_RenderTexture(m_state.renderer, idleTex, &src, &dst);

    // swap buffers
    SDL_RenderPresent(m_state.renderer);
  }
  SDL_DestroyTexture(idleTex);
}

void Game::Cleanup() {
  SDL_DestroyWindow(m_state.window);
  SDL_Quit();
}
