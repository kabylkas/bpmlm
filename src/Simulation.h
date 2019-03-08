#pragma once
#include "Person.h"
#include <vector>
#include <stdint.h>
#include <iostream>

class Simulation {
  private:
    uint32_t days;
    std::vector<Person*> people;

  public:
    Simulation();
    ~Simulation();
    void setup_me();
    void run_detailed();
    void set_days(uint32_t days);
};
