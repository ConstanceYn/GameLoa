#include "Pion.hpp"

// Constructeurs
Pion::Pion(): symbole(' '){}
Pion::Pion(char c): symbole(c){}

// Getters
char Pion::getSymbole()
{
    return symbole;
}
