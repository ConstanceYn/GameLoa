#include "Case.hpp"

// Constructeurs
Case::Case(int x, int y)
{
    Pion p = Pion(x, y);
    pion = &p;
}

Case::Case(Pion * p): pion(p) {}


// Getter
Pion Case::getPion()
{
    return * pion;
}

Pion * Case::getPionPointeur(){
    return pion;
}

// add/remove Pion
void Case::addPion(Pion p)
{
    pion = &p;
}
void Case::removePion()
{
    Pion p = Pion(pion->getI(), pion->getJ());
    pion = &p;
}


/*
Case::Case(Objet o):objet(o) {}
Objet &Case::getObjet()
{
    return objet;
}
void Case::addObjet(const Objet& o)
{
    objet = o
}*/



// Affichage
ostream& operator<<(ostream& out, Case c)
{
    // if (c.pion.getSymbole() == ' ')
    //     out << c.objet.getSymbole();

    out << c.pion->getSymbole();
    return out;
}
