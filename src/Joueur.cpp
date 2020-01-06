#include "Joueur.hpp"
#include "Plateau.hpp"

//Joueur::Joueur(int x, int y): Pion('J', x, y), nbDiam(0), sortie(false), nbTp(0) {}
Joueur::Joueur(int x, int y): Pion('J', x, y), sortie(false) {}

//Joueur::Joueur(int x, int y, int t): Pion('J', x, y), nbDiam(0), sortie(false), nbTp(t) {}


void Joueur::addDiam()
{
    nbDiam += 1;
    if (nbDiam == 1)
        sortie = true;
}
/*
void Joueur::addTp()
{
    nbTp += 1;
}
void Joueur::setTp(int t)
{
    nbTp = t;
}
*/

void Joueur::teleport(int x, int y, Plateau &p) // WHY DO U HATE ME SO MUCH ToT
{
    cout << "c'est moi !" << endl;
    char c = p.getCase(x, y).getPion().getSymbole();
    while (c != ' ' && c != '$' && c != '*' && c != '+'){ // je voulais utiliser move mais il veut pas :(
      srand(time(NULL));
      x = rand()%p.sizeI();
      srand(time(NULL));
      y = rand()%p.sizeJ();
      c = p.getCase(x, y).getPion().getSymbole();
    }
    moving(x, y, p);
}

bool Joueur::getSortie() const
{
    return sortie;
}
