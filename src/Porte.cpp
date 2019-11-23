#include "Porte.hpp"

Porte::Porte(): Case('-'), ouverte(false){}

void Porte::ouverture()
{
    ouverte = true;
    symbole = '+';
}
