#ifndef GAME_H
#define GAME_H

#include <random>
#include <memory>
#include <future>
#include <chrono>
#include <mutex>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "bonus_food.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  std::unique_ptr<SDL_Point> food = nullptr;
  BonusFood bonus_food;
  std::unique_ptr<bool> bonus_eaten = std::make_unique<bool>(false);
  std::unique_ptr<bool> bonus_valid = std::make_unique<bool>(false);
  std::future<int> bonus_ftr;
  int bonus_cntr = 0;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};
  std::mutex score_mtx;
  std::mutex bonus_mtx;

  void PlaceFood();
  void Update();
};

#endif