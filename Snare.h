#ifndef SNARE_H
#define SNARE_H
#include "Influence.h"
#include "Spot.h"

class Snare : public Spot, public Influence {
 protected:
  bool operative;

 public:
  Snare(int x, int y) : Spot(x, y, 'S') {}

  bool isOperative() { return operative; };

  void implement(Spot& spot) override {
    spot = Spot(0, 0, 'S');
    operative = false;
  }
};

#endif