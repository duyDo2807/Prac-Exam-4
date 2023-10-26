#ifndef PLAY_H
#define PLAY_H

#include <ctime>
#include <iostream>
#include <vector>

#include "Assists.h"
#include "Persona.h"
#include "Snare.h"
#include "Spot.h"

class Play {
 public:
  Play() {}

  std::vector<Spot*>& getMatrix() { return matrix; }

  void initPlay(int numPersonas, int numSnares, int matrixWidth,
                int matrixHeight) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (int i = 0; i < numPersonas; i++) {
      int x = std::rand() % matrixWidth;
      int y = std::rand() % matrixHeight;
      Persona* persona = new Persona(x, y);
      matrix.push_back(persona);
    }

    for (int i = 0; i < numSnares; i++) {
      int x = std::rand() % matrixWidth;
      int y = std::rand() % matrixHeight;
      Snare* snare = new Snare(x, y);
      matrix.push_back(snare);
    }
  }

  bool checkVictory(Persona& persona, int matrixWidth) {
    std::tuple<int, int> loc = persona.getLoc();
    int x = std::get<0>(loc);
    return x >= matrixWidth;
  }

  void movePersonasRight() {
    for (Spot* spot : matrix) {
      if (dynamic_cast<Persona*>(spot) != nullptr) {
        Persona* persona = dynamic_cast<Persona*>(spot);
        persona->shift(1, 0);
      }
    }
  }

  void activateSnares(double snareTriggerDistance) {
    for (Spot* spot : matrix) {
      if (dynamic_cast<Persona*>(spot) != nullptr) {
        Persona* persona = dynamic_cast<Persona*>(spot);
        for (Spot* s : matrix) {
          if (dynamic_cast<Snare*>(s) != nullptr) {
            Snare* snare = dynamic_cast<Snare*>(s);
            double distance =
                Assists::evaluateDistance(persona->getLoc(), snare->getLoc());
            if (distance <= snareTriggerDistance) {
              snare->implement(*persona);
            }
          }
        }
      }
    }
  }

  void playCycle(int maxCycles, double snareTriggerDistance) {
    for (int cycle = 1; cycle <= maxCycles; cycle++) {
      movePersonasRight();
      activateSnares(snareTriggerDistance);

      for (Spot* spot : matrix) {
        if (dynamic_cast<Persona*>(spot) != nullptr) {
          Persona* persona = dynamic_cast<Persona*>(spot);
          if (checkVictory(*persona, 10)) {
            std::cout << "Persona has won the game!" << std::endl;
            return;
          }
        }
      }

      if (cycle == maxCycles) {
        std::cout << "Maximum number of cycles reached. Game over."
                  << std::endl;
        return;
      }
    }
  }

 private:
  std::vector<Spot*> matrix;
};

#endif