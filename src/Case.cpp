#include "Case.hpp"

// Constructeurs
Case::Case(int x, int y): pion(Pion(x,y)) {}
Case::Case(Pion p): pion(p) {}


// Getter
Pion &Case::getPion()
{
    return pion;
}

// add/remove Pion
void Case::addPion(Pion& p)
{
    pion = p;
}
void Case::removePion()
{
    pion = Pion(pion.getI(), pion.getJ());
    cout << "I do my job" << endl;
    pion.setSymbole(' ');
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

    out << c.pion.getSymbole();
    return out;
}
