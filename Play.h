#ifndef PLAY_H
#define PLAY_H

class Play {
 public:
  Game(){};

  std::vector<GameEntity*> get_entities() { return entities; };

  void set_entities(std::vector<GameEntity*> entities) { entities = entities; };

  std::vector<GameEntity*> initGame(int numShips, int numMines, int gridWidth,
                                    int gridHeight) {
    for (int i = 0; i < numShips; i++) {
      std::tuple<int, int> shipPos =
          Utils::generateRandomPos(gridWidth, gridHeight);
      entities.push_back(new Ship(std::get<0>(shipPos), std::get<1>(shipPos)));
    }

    for (int i = 0; i < numMines; i++) {
      std::tuple<int, int> minePos =
          Utils::generateRandomPos(gridWidth, gridHeight);
      entities.push_back(new Mine(std::get<0>(minePos), std::get<1>(minePos)));
    }

    return entities;
  };

  void gameLoop(int maxIterations, double mineDistanceThreshold) {
    for (int iteration = 0; iteration < maxIterations; iteration++) {
      // Call move(1, 0) for all Ship objects
      for (GameEntity* entity : entities) {
        if (entity->getType() == 'S') {
          Ship* ship = dynamic_cast<Ship*>(entity);
          if (ship != nullptr) {
            ship->move(1, 0);
          }
        }
      }

      // Check if any Ship is within the mineDistanceThreshold of a Mine and
      // explode it
      for (GameEntity* ship : entities) {
        if (ship->getType() == 'S') {
          for (GameEntity* mine : entities) {
            if (mine->getType() == 'M') {
              double distance =
                  Utils::calculateDistance(ship->getPos(), mine->getPos());
              if (distance < mineDistanceThreshold) {
                Mine* mineObj = dynamic_cast<Mine*>(mine);
                if (mineObj != nullptr) {
                  Explosion explosion = mineObj->explode();
                }
              }
            }
          }
        }
      }
    }
  };

 private:
  std::vector<GameEntity*> entities;
};

#endif