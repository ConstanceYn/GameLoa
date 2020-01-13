#include "MonstreNul.hpp"
#include "Plateau.hpp"

MonstreNul::MonstreNul(int x, int y):Monstre(x , y){
    setSymbole('n');
}

bool MonstreNul::teleport(int x, int y, Plateau& p)
{
  if (!bouge){
    int a = (rand()%3)-1;
    int b = (rand()%3)-1;
    bouge = true;
    return moving(y+a, x+b, p);
  }
  return false;
}
