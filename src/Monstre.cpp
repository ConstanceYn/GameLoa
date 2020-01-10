#include "Monstre.hpp"
#include "Plateau.hpp"

Monstre::Monstre(int x, int y):Pion('m', x , y), bouge(false), diamant(false), chargeur(false) {}

void Monstre::resetBouge(){
    bouge = false;
}

bool Monstre::moving(int x, int y, Plateau& p)
{
    cout << "let's go pokemon" << endl;
    bool b = move(x, y, p);
    if (b){
        int csti = i;
        int cstj = j;
        i = x;
        j = y;
        Pion * cible = p.getCase(x,y);
        if (cible->getSymbole() == 'J'){
            // MANGE JOUEUR -> PERDU
        }
        p.setCase(x,y,p.getCase(csti,cstj));
        if (diamant){
            p.setCase(csti,cstj,new Diamant(csti,cstj));
            diamant = false;
        }else{
            if (chargeur){
                p.setCase(csti,cstj,new Chargeur(csti,cstj));
                chargeur = false;
            }else{
                p.setCase(csti,cstj,new Pion(' ',csti,cstj));
            }
        }
        if (cible->getSymbole() == '$'){
            diamant = true;
        }
        if (cible->getSymbole() == '*'){
            chargeur = true;
        }
        delete cible;
    }
    return b;
}

void Monstre::teleport(int x, int y, Plateau& p)
{
  if (!bouge){
    cout << "Bouge toi" << endl;
    for (size_t i = 0; i < p.sizeI(); i++) { // i est la hauteur !!
      for (size_t j = 0; j < p.sizeJ(); j++) { // j est la largeur !!
        if (p.getCase(i, j)->getSymbole()== 'J')
        {
          if (i > y){
            y++;
          }else{
            if (i < y){
              y--;
            }
          }
          if (j > x){
            x++;
          }else{
            if (j < x){
              x--;
            }
          }
        }
      }
    }
    bouge = true;
    moving(y, x, p);
  }
}
