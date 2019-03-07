#pragma once

#include <cstdlib>
#include <ctime>
#include <stdint.h>

class Chance {
  private:
    uint32_t seed;

  public:
    Chance(uint32_t seed);
    Chance();
    ~Chance();
    bool success(double conv);
};
