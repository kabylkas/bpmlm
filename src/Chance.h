#pragma once

#include <cstdlib>
#include <ctime>
#include <stdint.h>
#include <chrono>

class Chance {
  private:
    uint32_t seed;
    uint32_t ppl_range_a;
    uint32_t ppl_range_b;

  public:
    Chance(uint32_t seed);
    Chance();
    ~Chance();
    bool success(double conv);
    uint32_t get_init_pool();
    double get_conv();
};
