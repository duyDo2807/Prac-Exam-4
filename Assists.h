#ifndef ASSISTS_H
#define ASSISTS_H
#include <cmath>
#include <cstdlib>

#include "Spot.h"

class Assists {
 public:
  static std::tuple<int, int> createRandomLoc(int matrixWidth,
                                              int matrixHeight) {
    int x = std::rand() % (matrixWidth + 1);
    int y = std::rand() % (matrixHeight + 1);
    return std::make_tuple(x, y);
  }

  static double evaluateDistance(std::tuple<int, int> loc1,
                                 std::tuple<int, int> loc2) {
    int x1, y1, x2, y2;
    std::tie(x1, y1) = loc1;
    std::tie(x2, y2) = loc2;

    double distance = std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return distance;
  }
};

#endif