#include "Porte.hpp"

Porte::Porte(): Case(PORTEF), ouverte(false){}

void Porte::ouverture()
{
    ouverte = true;
    pion = PORTEO;
}
