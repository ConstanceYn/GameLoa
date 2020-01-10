#include "Monstre.hpp"
#include "Plateau.hpp"

Monstre::Monstre(int x, int y):Pion('m', x , y) {}

void Monstre::teleport(int x, int y, Plateau& p)
{
  cout << "Bouge toi" << endl;
  for (size_t i = 0; i < p.sizeI(); i++) { // i est la hauteur !!
      for (size_t j = 0; j < p.sizeJ(); j++) { // j est la largeur !!
          if (p.getCase(i, j)->getSymbole()== 'J')
          {
              if (i > x){
                  x++;
              }else{
                  if (i < x){
                      x--;
                  }
              }
              if (j > y){
                  y++;
              }else{
                  if (j < y){
                      y--;
                  }
              }
          }
      }
    }
    moving(x, y, p);
}
