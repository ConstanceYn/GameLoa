#include "Pion.hpp"
#include "Plateau.hpp"

// Constructeurs


// Nous avons un problème avec ses constructeurs, ils sont appelé quelque part et je ne trouve pas ou
//  Le pire c'est qu'ils sont appelés avant le programme ????
// Si on les enlève le code ne compile plus
// je ne comprends rien, tuez moi

// Pion::Pion(){cout << "j'existe quelque part visiblement"<< endl;}
// Pion::Pion(char c) {cout << "moi aussi askip " << endl;}


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
        p.getCase(x, y).addPion(*this); // déplace pion dans sa nouvelle case
        // add à revoir car pas tester pour l'instant (oui ou non * ?)
        p.getCase(i, j).removePion(); // retire pion de son ancienne case
        cout << "I hate you : " << p.getCase(i, j) << endl;
        i = x;
        j = y;
    }
    return b;
}

void Pion::actionPion(Personne p){}
