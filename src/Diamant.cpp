#include "Diamant.hpp"

Diamant::Diamant(int x, int y): Pion('$', x, y){}

void Diamant::actionPion(Personne p){
  p.addElement(1, 0);
}
