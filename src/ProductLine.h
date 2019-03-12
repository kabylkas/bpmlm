#pragma once
#include <stdint.h>
#include "Chance.h"

class ProductLine {
  private:
    uint32_t num_products;
    Chance chance;
  public:
    ProductLine();
    ~ProductLine();
    uint32_t draw_product();
};
