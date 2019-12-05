#include "Case.hpp"

// Constructeurs
Case::Case(): pion(VIDE){}
Case::Case(Pion p): pion(p) {}

// Affichage
ostream& operator<<(ostream& out, Case c)
{
    out << c.pion.getSymbole();
    return out;
}
