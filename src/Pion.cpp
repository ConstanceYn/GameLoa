#include "Pion.hpp"
#include "Plateau.hpp"

// Constructeurs

Pion::Pion(int x, int y): symbole(' '), i(x), j(y){}
Pion::Pion(char c, int x, int y): symbole(c), i(x), j(y){}

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

bool Pion::move(const int x, const int y, Plateau p)
{
    char cible = p.getCase(x, y).getPion().getSymbole();
    if (cible == ' ' || cible == '$' || cible == '*' || cible == '+'){ // case "vide"
        //if (x >= i-1 && x <= i+1 && y >= j-1 && y <= j+1){ // case adjacente
            return !(x == i && y == j); // la case où on se trouve actuellement
        //}
    }
    return false;
}

bool Pion::moving(const int x, const int y, Plateau& p)
{
    bool b = move(x, y, p);
    if (b){
        int csti = i;
        int cstj = j;
        i = x;
        j = y;
        p.getCase(x, y).addPion(*this); // déplace pion dans sa nouvelle case
        // add à revoir car pas tester pour l'instant (oui ou non * ?)

        p.getCase(csti, cstj).removePion(); // retire pion de son ancienne case
    }
    return b;
}

void Pion::actionPion(Personne p){}

void Pion::teleport(int x, int y, Plateau &p)
{
    cout << "non c'est moi " << endl;
    char c = p.getCase(x, y).getPion().getSymbole();
    while (c != ' ' && c != '$' && c != '*' && c != '+'){ // je voulais utiliser move mais il veut pas :(
      srand(time(NULL));
      x = rand()%p.sizeI();
      srand(time(NULL));
      y = rand()%p.sizeJ();
      c = p.getCase(x, y).getPion().getSymbole();
    }
    moving(x, y, p);
}
