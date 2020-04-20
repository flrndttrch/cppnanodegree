#ifndef BONUS_FOOD_H
#define BONUS_FOOD_H

#include <chrono>
#include <thread>
#include <mutex>
#include <algorithm>

class BonusFood {
 public:
  int PlaceBonusFood(bool *eaten);
  void SetPoint(int x, int y);
  bool IsValid() const {return valid;}
  SDL_Point GetPoint() const {return point;}
    
 private:
  SDL_Point point = {-1, -1};
  bool valid = false;
};

#endif