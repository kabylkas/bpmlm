#include "Chance.h"

Chance::Chance(uint32_t seed) {
  this->seed = seed;
  std::srand(seed);
}

Chance::Chance() {
  this->seed = std::time();
  std::srand(seed);
}

Chance::~Chance() {

}

bool Chance::success(double conv) {
  double r = std::rand()/std::RAND_MAX;
  return (r <= conv);
}
