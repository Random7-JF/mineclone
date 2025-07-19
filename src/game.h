#pragma once
#include <SDL3/SDL.h>
#include <array>
#include <vector>
#include <string>

#include "gameObject.h"

struct SDLState {
  SDL_Window *window;
  SDL_Renderer *renderer;
  int width, height, game_width, game_height;
};

const size_t Layer_Index_Level = 0;
const size_t Layer_Index_Characters = 1;

struct GameState
{
  std::array<std::vector<GameObject>, 2> layers;
  int playerIndex;
  
  GameState()  {
    playerIndex = 0;
  }
};

class Game {
  private:
    SDLState m_state;
  public:
    bool Init();
    void Cleanup();
    void Run();
    SDLState getState() { return m_state; }
    explicit Game(int width, int height, int game_width, int game_height);
   private:
    void drawObject(GameState &gs, GameObject &obj, float deltaTime);
};
