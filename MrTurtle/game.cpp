#include "game.hpp"

typedef enum GAME_STATE {TITLE_SCREEN = 0, GAME, RUN} GAME_STATE;

// functions with internal linkage
// -> bound to this translation unit
static void display_title_screen();
static void display_game();
static void display_end_screen();

// set initial game state to title_screen
static GAME_STATE current_state = TITLE_SCREEN;

Game::Game() noexcept 
  : player(40, 100), water_speed(10.f)
{
  water = LoadTexture("./water.png");
}

void Game::unload_textures() {
  UnloadTexture(water);
}

void Game::run() {
  BeginDrawing();
  update();
  EndDrawing();
}

void Game::update() {
  switch(current_state) {
    case TITLE_SCREEN: display_title_screen(); break;
    case GAME: display_game(); break;
    case RUN: display_end_screen(); break;
  }
}

void Game::display_title_screen() {
  ClearBackground(RAYWHITE);
  float delta = GetFrameTime();
  DrawTextureRec(water, {water_one.x, 0, 1280, 200}, {0, 0}, WHITE);
  water_one.x -= 200 * delta;

  DrawTextureRec(water, {water_two.x, 0, 1280, 200}, {0, 200}, WHITE);
  water_two.x -= 150 * delta;

  DrawTextureRec(water, {water_three.x, 0, 1280, 200}, {0, 400}, WHITE);
  water_three.x -= 220 * delta;

  DrawTextureRec(water, {water_four.x, 0, 1280, 200}, {0, 600}, WHITE);
  water_four.x -= 100 * delta;
  player.draw_player();
  player.move_player();
}
void Game::display_game() {
  ClearBackground(RAYWHITE);
}
void Game::display_end_screen() {
  ClearBackground(RAYWHITE);

}
