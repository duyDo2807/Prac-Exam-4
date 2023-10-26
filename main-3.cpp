#include <iostream>

#include "Play.h"

int main() {
  Play myGame;
  std::vector<Spot*> spots = myGame.getMatrix();

  myGame.playCycle(5, 2.0);

  // Clean up the entities to avoid memory leaks
  for (auto spot : spots) {
    delete spot;
  }

  return 0;
}