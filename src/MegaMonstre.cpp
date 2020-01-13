#include "MegaMonstre.hpp"
#include "Plateau.hpp"

MegaMonstre::MegaMonstre(int x, int y):Monstre(x , y){
    setSymbole('M');
}

bool MegaMonstre::moving(int x, int y, Plateau& p)
{
    bool b = move(x, y, p);
    if (b){
        int csti = i;
        int cstj = j;
        i = x;
        j = y;
        Pion * cible = p.getCase(x,y);
        p.setCase(x,y,p.getCase(csti,cstj));
        if (diamant){
            p.setCase(csti,cstj,new Diamant(csti,cstj));
            diamant = false;
        }else{
            p.setCase(csti,cstj,new Pion(' ',csti,cstj));
        }
        if (cible->getSymbole() == '$'){
            diamant = true;
        }
        if (cible->getSymbole() == 'J'){
            cout << "NOM NOM NOM" << endl;
            return true;
        }
        delete cible;
    }
    return false;
}


bool MegaMonstre::teleport(int x, int y, Plateau& p)
{
  if (!bouge){
      x = rand()%p.sizeI();
      y = rand()%p.sizeJ();
      char c = p.getCase(x, y)->getSymbole();
      while (!move(x,y,p)){
          x = rand()%p.sizeI();
          y = rand()%p.sizeJ();
          c = p.getCase(x, y)->getSymbole();
      }
      bouge = true;
      return moving(x, y, p);
  }
  return false;
}
