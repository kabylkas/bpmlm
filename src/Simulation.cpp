#include "Simulation.h"

Simulation::Simulation() {

}

Simulation::~Simulation() {

}

void Simulation::run_detailed() {
  for (uint32_t day = 0; day < this->days; day++) {
    for (uint32_t i = 0; i < this->people.size(); i++) {
      Person p = this->people[i];
      p.find_connections();
      p.learn();
      p.invite_to_training();
      p.invite_to_meeting();
      p.invite_to_meeting3();

      bool success = p.invite_to_school();
      if (success) {
        //create a person
      }
    }
  }
}

void Simulation::set_days(uint32_t days) {
  this->days = days;
}
