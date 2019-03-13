#include "Chance.h"
#include <iostream>

int main() {
  Chance c;
  double conv = 0.25;
  int iters = 1000;
  double sum = 0.0;
  for (int tests = 0; tests < iters; tests++) {
    int s = 0;
    int f = 0;
    for (uint32_t i = 0; i < 1000; i++) {
      bool flip = c.success(conv);
      if (flip) {
        s++;
      } else {
        f++;
      }
    }
    double ratio = s/(f/1.0);
    sum += ratio;
    std::cout << s << "/" << f << "; ";
    std::cout << "Ratio: " << ratio << std::endl;
  }
  std::cout << "----------------" << std::endl;
  std::cout << "Conv  = " << conv << std::endl;
  std::cout << "Ave   = " << sum/(iters/1.0) << std::endl;
  std::cout << "----------------" << std::endl;

  for (uint32_t i = 0; i < 100; i++) {
    std::cout << c.get_conv() << std::endl;
  }
  return 0;
}
