#include "Porte.hpp"

Porte::Porte(int x, int y): Pion('-', x, y), ouverte(false){}


void Porte::ouverture()
{
    ouverte = true;
    symbole = '+';
}
