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
        cout << "test 1 ok" << endl;
        cout << "x = " << x << "et i = " << i << endl;
        cout << "y = " << y << "et j = " << j << endl;
        if (x >= i-1 && x <= i+1 && y >= j-1 && y <= j+1){ // case adjacente
            cout << "test 2 ok" << endl;
            return !(x == i && y == j); // la case où on se trouve actuellement
        }
    }
    return false;
}

bool Pion::moving(const int x, const int y, Plateau& p)
{
    cout << "x "<< x << " et y " << y<< endl;
    bool b = move(x, y, p);
    if (b){
        p.getCase(x, y).addPion(*this); // déplace pion dans sa nouvelle case
        // add à revoir car pas tester pour l'instant (oui ou non * ?)
        p.getCase(i, j).removePion(); // retire pion de son ancienne case
        i = x;
        j = y;
    }
    char c = b? 'o': 'n';
    cout << "Mouvement possible ? " << c << endl;
    return b;
}
