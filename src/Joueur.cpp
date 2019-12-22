#include "Joueur.hpp"
#include "Plateau.hpp"

Joueur::Joueur(int x, int y): Pion('J', x, y), nbDiam(0), sortie(false), nbTp(0) {}

Joueur::Joueur(int x, int y, int t): Pion('J', x, y), nbDiam(0), sortie(false), nbTp(t) {}

void Joueur::addDiam()
{
    nbDiam += 1;
    if (nbDiam == 1)
        sortie = true;
}
void Joueur::addTp()
{
    nbTp += 1;
}
void Joueur::setTp(int t)
{
    nbTp = t;
}

bool Joueur::getSortie() const
{
    return sortie;
}
