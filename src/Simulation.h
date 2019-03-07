#pragma once
#include "Person.h"
#include <vector>
#include <stdint.h>

class Simulation {
  private:
    uint32_t days;
    std::vector<Person> people;

  public:
    Simulation();
    ~Simulation();
    void run_detailed();
    void set_days(uint32_t days);
};
