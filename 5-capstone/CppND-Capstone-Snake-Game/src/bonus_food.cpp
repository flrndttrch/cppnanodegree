#include "SDL.h"
#include "bonus_food.h"
#include <iostream>

using namespace std::chrono;

void BonusFood::SetPoint(int x, int y) {
  point = {x,y};
  valid = true;
}

int BonusFood::PlaceBonusFood(bool *eaten) {
  int max_dur = 5000;
  milliseconds start = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
  milliseconds end = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
  duration<long int, std::milli> diff = end-start;
  
  while (diff.count() < max_dur && *eaten == false) {
    std::this_thread::sleep_for(milliseconds(100));
    end = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
  	diff = end - start;
  }  
  return std::max(0, (int)((max_dur - diff.count()) / 1000));
}