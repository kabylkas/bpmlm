#include "Chance.h"

Chance::Chance(uint32_t seed) {
  this->seed = seed;
  std::srand(seed);
}

Chance::Chance() {
  this->seed = std::time(nullptr);
  std::srand(seed);
}

Chance::~Chance() {

}

bool Chance::success(double conv) {
  double r = std::rand()/(RAND_MAX/1.0);
  return (r <= conv);
}
