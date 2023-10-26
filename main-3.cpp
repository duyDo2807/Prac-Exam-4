#include <iostream>

#include "Play.h"

int main() {
  Play myGame;
  std::vector<Spot*> entities = myGame.getMatrix();

  std::cout << "Initial Spots:\n";
  for (auto entity : entities) {
    std::cout << "Type: " << entity->getCategory() << ", Position: ("
              << std::get<0>(entity->getLoc()) << ", "
              << std::get<1>(entity->getLoc()) << ")\n";
  }

  myGame.playCycle(5, 2.0);

  std::cout << "Game Entities after Simulation:\n";
  for (auto entity : myGame.getMatrix()) {
    std::cout << "Type: " << entity->getCategory() << ", Position: ("
              << std::get<0>(entity->getLoc()) << ", "
              << std::get<1>(entity->getLoc()) << ")\n";
  }

  // Clean up the entities to avoid memory leaks
  for (auto entity : entities) {
    delete entity;
  }

  return 0;
}