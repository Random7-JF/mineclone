#pragma once
#include "app.h"
#include <SDL3/SDL.h>

class Game {
private:
  AppState *m_AppState;
  bool Run();

public:
  explicit Game(AppState *m_AppState) : m_AppState(m_AppState) {}
  bool InitAndRun();
};
