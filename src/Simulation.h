#pragma once
#include "Person.h"
#include "ProductLine.h"
#include <vector>
#include <stdint.h>
#include <iostream>
class Simulation {
  private:
    ProductLine products;
    uint32_t days;
    double people_activity_rate;
    std::vector<Person*> people;

  public:
    Simulation();
    ~Simulation();
    void reset();
    void set_people_activity_rate(double rate);
    void setup_me();
    void run_detailed();
    void set_days(uint32_t days);
    Person* create_person(Person* inviter);
    Person* get_me();
};
