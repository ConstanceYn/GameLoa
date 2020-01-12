#include "Porte.hpp"

Porte::Porte(int x, int y): Pion('-', x, y), ouverte(false){}
Porte::Porte(int x, int y, bool b): Pion('+', x, y), ouverte(b){}


void Porte::ouverture()
{
    ouverte = true;
    symbole = '+';
}
