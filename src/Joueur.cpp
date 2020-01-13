#include "Joueur.hpp"
#include "Plateau.hpp"

//Joueur::Joueur(int x, int y): Pion('J', x, y), sortie(false) {}
Joueur::Joueur(int x, int y): Pion('J', x, y) {}

bool Joueur::moving(const int x, const int y, Plateau& p)
{
    bool b = move(x, y, p);
    if (b){
        int csti = i;
        int cstj = j;
        i = x;
        j = y;
        Pion * cible = p.getCase(x,y);
        p.setCase(x,y,p.getCase(csti,cstj));
        Pion * vide = new Pion(' ', csti,cstj);
        p.setCase(csti,cstj,vide);
        if (cible->getSymbole() == '$'){
            p.parsePorte();
        }
        delete cible;
    }
    return b;
}

bool Joueur::teleport(int x, int y, Plateau &p)
{
    char c = p.getCase(x, y)->getSymbole();
    while (!move(x,y,p)){
      x = rand()%p.sizeI();
      y = rand()%p.sizeJ();
      c = p.getCase(x, y)->getSymbole();
    }
    return moving(x, y, p);
}
//
// bool Joueur::getSortie() const
// {
//     return sortie;
// }
