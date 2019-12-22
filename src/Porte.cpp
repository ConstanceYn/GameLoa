#include "Porte.hpp"

Porte::Porte(int x, int y): Case(Pion('-', x, y)), ouverte(false){}

void Porte::ouverture()
{
    ouverte = true;
    pion.setSymbole('+');
}
