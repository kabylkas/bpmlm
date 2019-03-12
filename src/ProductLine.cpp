#include "ProductLine.h"

ProductLine::ProductLine() {

}

ProductLine::~ProductLine() {

}

uint32_t ProductLine::draw_product() {
  uint32_t points = 0;
  //FIXME: make this more generic
  bool standard = chance.success(0.8);
  if (standard) {
    points = 100;
  } else {
    bool premium = chance.success(0.9);
    if (premium) {
      points = 600;
    } else {
      points = 2000;
    }
  }

  return points;
}
