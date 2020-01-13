#include "Pion.hpp"
#include "Plateau.hpp"

// Constructeurs

Pion::Pion(int x, int y): symbole(' '), i(x), j(y){}
Pion::Pion(char c, int x, int y): symbole(c), i(x), j(y){}

//Pion::~Pion(){}

// Getters
char Pion::getSymbole() const
{
    return symbole;
}

int Pion::getI() const
{
    return i;
}

int Pion::getJ() const
{
    return j;
}

void Pion::setSymbole(char c)
{
    symbole = c;
}

void Pion::resetBouge(){}

bool Pion::move(const int x, const int y, Plateau p)
{
    char cible = p.getCase(x, y)->getSymbole();
    if (cible == ' ' || cible == '$' || cible == '*' || cible == '+' || cible == 'J') // case "vide"
            return !(x == i && y == j); // la case où on se trouve actuellement
    return false;
}

bool Pion::moving(const int x, const int y, Plateau& p)
{
    return false;
}

void Pion::actionPion(Personne p){}

void Pion::ouverture(){}

bool Pion::teleport(int x, int y, Plateau &p)
{
    return false;
}
