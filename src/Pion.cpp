#include "Pion.hpp"
#include "Plateau.hpp"

// Constructeurs
Pion::Pion(): symbole(' '){}
Pion::Pion(char c): symbole(c){}

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

bool Pion::move(const int x, const int y, const Plateau p)
{
  char cible = p.getCase(x, y).getPion().getSymbole();
  if (cible == ' ' || cible == '$' || cible == '*' || cible == '+'){ // case "vide"
    if (x >= i-1 && x <= i+1 && y >= j-1 && y <= j+1){ // case adjacente
      return !(x == i && y == j); // la case où on se trouve actuellement
    }
  }
  return false;
}

bool Pion::moving(const int x, const int y, Plateau p)
{
  bool b = move(x, y, p);
  if (b){
    p.getCase(x, y).addPion(*this); // déplace pion dans sa nouvelle case
    // add à revoir car pas tester pour l'instant (oui ou non * ?)
    p.getCase(i, j).removePion(); // retire pion de son ancienne case
    i = x;
    j = y;
  }
  return b;
}
