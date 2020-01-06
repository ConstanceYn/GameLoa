#include "Personne.hpp"

Personne::Personne(): diam(0), tp(2){}

void Personne::addElement(int d, int t)
{
    diam += d;
    tp += t;
}

int Personne::getTp() const
{
    return tp;
}

ostream& operator<<(ostream& out, Personne p)
{
    out << "Nombre de Diamant : " << p.diam << endl;
    out << "Nombre de Chargeur : " <<p.tp << endl;
    return out;
}

void teleport(){}
