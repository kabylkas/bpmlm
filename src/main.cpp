#include "Simulation.h"
#include "Person.h"
#include <iostream>
#include <map>
#include <fstream>

int main() {
  Simulation sim;

  // set up
  sim.set_days(1000);
  sim.set_people_activity_rate(0.2);

  // run
  std::map<uint32_t, uint32_t> histogram;
  uint32_t max_idx = 0;
  for (uint32_t i = 0; i < 10000; i++) {
    sim.reset();
    sim.setup_me();
    sim.run_detailed();

    // some stats
    uint32_t bucket_size = 1000;
    #ifdef TRACE
    std::cout << "L: " << sim.get_me()->get_left_points() << " R: " << sim.get_me()->get_right_points() << std::endl;
    #endif
    uint32_t money = sim.get_me()->get_left_points();
    if (sim.get_me()->get_right_points() > money) {
      money = sim.get_me()->get_right_points();
    }
    uint32_t bucket_idx = money / bucket_size;
    if (bucket_idx > max_idx) {
      max_idx = bucket_idx;
    }
    histogram[bucket_idx];
    histogram[bucket_idx]++;

    std::cout << i << ". Cash = " << money << std::endl;
  }

  std::ofstream outfile;
  outfile.open("bpmlm_results.txt");
  for (uint32_t i = 0; i < max_idx; i++) {
    uint32_t to_print = 0;
    if (histogram.find(i) != histogram.end()) {
      to_print = histogram[i];
    }

    outfile << to_print << std::endl;
  }
  outfile.close();
  return 0;
}
