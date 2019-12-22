#include "Case.hpp"

// Constructeurs
Case::Case(int x, int y): pion(Pion(x,y)){}
Case::Case(Pion p): pion(p) {}

// Getter
Pion &Case::getPion()
{
    return pion;
}

// add/remove Pion
void Case::addPion(const Pion& p)
{
    pion = p;
}

void Case::removePion()
{
    pion = Pion(pion.getI(), pion.getJ());
}

// Affichage
ostream& operator<<(ostream& out, Case c)
{
    out << c.pion.getSymbole();
    return out;
}
