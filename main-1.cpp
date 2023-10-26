#include <ctime>
#include <iostream>

#include "Assists.h"
#include "Influence.h"
#include "Spot.h"

int main() {
  std::srand(
      static_cast<unsigned>(std::time(nullptr)));  // Initialize random seed

  int matrixWidth = 5;
  int matrixHeight = 5;

  // Generate random positions and calculate distances
  for (int i = 0; i < 5; i++) {
    std::tuple<int, int> pos1 =
        Assists::createRandomLoc(matrixWidth, matrixHeight);
    std::tuple<int, int> pos2 =
        Assists::createRandomLoc(matrixWidth, matrixHeight);

    double distance = Assists::evaluateDistance(pos1, pos2);

    std::cout << "Position 1: (" << std::get<0>(pos1) << ", "
              << std::get<1>(pos1) << ")" << std::endl;
    std::cout << "Position 2: (" << std::get<0>(pos2) << ", "
              << std::get<1>(pos2) << ")" << std::endl;
    std::cout << "Distance: " << distance << std::endl;
  }

  return 0;
}