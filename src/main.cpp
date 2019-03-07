#include "Simulation.h"
#include <iostream>

int main() {
  Simulation sim;
  sim.set_days(1000);
  sim.run_detailed();
  return 0;
}
