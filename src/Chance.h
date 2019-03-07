#pragma once

#include <cstdlib>
#include <ctime>

class Chance {
  private:
    uint32_t seed;

  public:
    Chance(uint32_t seed);
    ~Chance();
    bool success(double conv);
};
