#include <SDL3_image/SDL_image.h>

#include "game.h"


struct Resources
{
  const int ANIM_PLAYER_IDLE = 0;
  std::vector<Animation> playerAnims;
  std::vector<SDL_Texture *> textures;
  SDL_Texture *texIdle;

  SDL_Texture *loadTexture(SDL_Renderer *renderer, const std::string &filepath)  {
    SDL_Texture *tex = IMG_LoadTexture(renderer, filepath.c_str());
    SDL_SetTextureScaleMode(tex, SDL_SCALEMODE_NEAREST);
    textures.push_back(tex);
    return tex;
  }

  void load(SDLState &state)  {
    playerAnims.resize(5);
    playerAnims[ANIM_PLAYER_IDLE] = Animation(4, 0.8f);

    texIdle = loadTexture(state.renderer, "data/idle.png");
  }

  void unload()  {
    for (SDL_Texture *tex : textures) {
      SDL_DestroyTexture(tex);
    } 
  }
};

Game::Game(int width, int height, int game_width, int game_height)
{
  m_state.width = width;
  m_state.height = height;
  m_state.game_width = game_width;
  m_state.game_height = game_height;
}

bool Game::Init()
{
  bool initialized = false;

  if (!SDL_Init(SDL_INIT_VIDEO))
  {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
                             "Error Initializing SDL3", nullptr);
    return initialized;
  }

  m_state.window = SDL_CreateWindow("SDL", m_state.width, m_state.height, SDL_WINDOW_RESIZABLE);
  if (!m_state.window)
  {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
                             "Error creating window", m_state.window);
    return initialized;
  }

  m_state.renderer = SDL_CreateRenderer(m_state.window, NULL);
  if (!m_state.renderer)
  {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
                             "error creating renderer", m_state.window);
    return initialized;
  }
  initialized = true;
  return initialized;
}

void Game::Run()
{
  SDL_Log("running...");
  // config game presentation
  SDL_SetRenderLogicalPresentation(m_state.renderer, m_state.game_width, m_state.game_height, SDL_LOGICAL_PRESENTATION_LETTERBOX);

  // setup game date
  Resources res;
  res.load(m_state);

  GameState gs;
  GameObject player;
  player.type = ObjectType::player;
  player.texture = res.texIdle;
  player.animations = res.playerAnims;
  player.currentAnimation = res.ANIM_PLAYER_IDLE;
  gs.layers[Layer_Index_Characters].push_back(player);

  GameObject player2;
  player2.type = ObjectType::player;
  player2.texture = res.texIdle;
  player2.animations = res.playerAnims;
  player2.currentAnimation = res.ANIM_PLAYER_IDLE;
  player2.position = glm::vec2(150,150);
  gs.layers[Layer_Index_Characters].push_back(player2);


  const bool *keys = SDL_GetKeyboardState(nullptr);
  // TODO move player into class
  //float sprite_size = 32.0f;
  //float sprite_scale = 2.0f;
  //float player_x = (m_state.game_width / 2) - (sprite_size * sprite_scale);
  //float player_y = m_state.game_height - (sprite_size * sprite_scale);
  //float player_movespeed = 100.0f;
  //bool player_flip = false;

  // start game loop
  bool running = true;
  uint64_t prevTime = SDL_GetTicks();
  while (running)
  {
    // Setup delta time
    uint64_t nowTime = SDL_GetTicks();
    float delta = (nowTime - prevTime) / 1000.0f;

    // start event loop
    SDL_Event event{0};
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_EVENT_QUIT:
      {
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
    } // end of event loop
    for (auto &layer : gs.layers) {
      for (GameObject &obj: layer)
      {
        if (obj.currentAnimation != -1) {
          obj.animations[obj.currentAnimation].step(delta);
        }
      }
    }
    SDL_SetRenderDrawColor(m_state.renderer, 28, 20, 10, 255);
    SDL_RenderClear(m_state.renderer);
    // draw calls
    for (auto &layer : gs.layers) {
      for (GameObject &obj: layer)
      {
        drawObject(gs, obj, delta);
      }
    }

    // swap buffers
    SDL_RenderPresent(m_state.renderer);
    prevTime = nowTime;
  } // End game loop
  res.unload();
}

void Game::Cleanup()
{
  SDL_DestroyWindow(m_state.window);
  SDL_Quit();
}

void Game::drawObject(GameState &gs, GameObject &obj, float deltaTime) {
  SDL_FRect src{
      .x = 32 * 22,
      .y = 32,
      .w = 32,
      .h = 32};

  SDL_FRect dst{
      .x = obj.position.x,
      .y = obj.position.y,
      .w = 64,
      .h = 64};
  SDL_FlipMode flipmode = obj.direction == -1 ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
  SDL_RenderTextureRotated(m_state.renderer, obj.texture, &src, &dst, 0, nullptr, flipmode);
}