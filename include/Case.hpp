#ifndef CASE
#define CASE

#include "Pion.hpp"
#include <iostream>

using namespace std;

class Case {
protected :
    //Pion v; // None si aucun
             // None existe ?
             // J'ai mis en commentaire pour l'instant parce qu'il me faisait chier pour le constucteur

    // si un Pion, le symbole change, on récupère le symbole avec getSymbole
    char symbole;

public :
    Case(char c);

    // des fonctions qui modifient le contenu de la Case
    // add/remove Pion

    friend ostream& operator<<(ostream& out, Case c);

};

ostream& operator<<(ostream& out, Case c);
#endif
