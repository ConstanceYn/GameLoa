#include "Chargeur.hpp"

Chargeur::Chargeur(int x, int y):Pion('*', x, y){}

void Chargeur::actionPion(Personne p){
  p.addElement(0, 1);
}
