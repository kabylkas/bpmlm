#include "Chance.h"
#include <iostream>

int main() {
  Chance c(2);
  int s = 0;
  int f = 0;
  for (uint32_t i = 0; i < 1000; i++) {
    bool flip = c.success(0.2);
    if (flip) {
      s++;
    } else {
      f++;
    }
  }

  std::cout << s << "/" << f << std::endl;
  std::cout << "Ration: " << s/f << std::endl;
  return 0;
}
