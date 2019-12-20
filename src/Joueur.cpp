#include "Joueur.hpp"
#include "Plateau.hpp"

Joueur::Joueur(): Pion('J'), nbDiam(0), sortie(false), nbTp(0) {}

bool Joueur::move(int x, int y, Plateau p)
{
  char cible = p.getCase(x, y).getPion().getSymbole();
  if (cible == ' ' || cible == '$' || cible == '*' || cible == '+'){ // case "vide"
    if (x >= i-1 && x <= i+1 && y >= j-1 && y <= j+1){ // case adjacente
      return !(x == i && y == j); // la case où on se trouve actuellement
    }
  }
  return false;
}

bool Joueur::moving(int x, int y, Plateau p)
{
  bool b = move(x, y, p);
  if (b){
    p.getCase(x, y).addPion(*this); // déplace pion dans sa nouvelle case
    // add à revoir car pas tester pour l'instant (oui ou non * ?)
    p.getCase(i, j).removePion(); // retire pion de son ancienne case
  }
  return b;
}
