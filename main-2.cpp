#include <iostream>

#include "Persona.h"
#include "Snare.h"

int main() {
  Snare snare(5, 5);
  Persona persona(1, 1);

  persona.shift(2, 3);

  // Display snare and persona information
  std::cout << "Snare location: (" << std::get<0>(snare.getLoc()) << ", "
            << std::get<1>(snare.getLoc()) << ")\n";
  std::cout << "Persona position: (" << std::get<0>(persona.getLoc()) << ", "
            << std::get<1>(persona.getLoc()) << ")\n";

  return 0;
}