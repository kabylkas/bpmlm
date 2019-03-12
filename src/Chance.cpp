#include "Chance.h"

Chance::Chance(uint32_t seed) {
  this->seed = seed;
  std::srand(seed);
}

Chance::Chance() {
  std::chrono::high_resolution_clock m_clock;
  this->seed = std::chrono::duration_cast<std::chrono::milliseconds>(m_clock.now().time_since_epoch()).count();
  this->ppl_range_a = 50;
  this->ppl_range_b = 300;
  std::srand(this->seed);
}

Chance::~Chance() {

}

bool Chance::success(double conv) {
  double r = std::rand()/(RAND_MAX/1.0);
  return (r <= conv);
}

uint32_t Chance::get_init_pool() {
  uint32_t range = this->ppl_range_b - this->ppl_range_a;
  return this->ppl_range_a + (std::rand() % range);
}

double Chance::get_conv() {
  double r = std::rand()/(RAND_MAX/1.0);
  return r;
}
