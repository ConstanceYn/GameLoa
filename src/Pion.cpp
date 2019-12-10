#include "Pion.hpp"
#include "Plateau.hpp"

// Constructeurs
Pion::Pion(): symbole(' '){}
Pion::Pion(char c): symbole(c){}

// Getters
char Pion::getSymbole()
{
    return symbole;
}

int Pion::getI()
{
    return i;
}

int Pion::getJ()
{
    return j;
}
