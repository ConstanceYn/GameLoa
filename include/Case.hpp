#ifndef CASE
#define CASE

#include "Pion.hpp"

const Pion VIDE = Pion();

class Case {
protected :
    Pion pion; // Pion "vide" si aucun
    // On récupère le symbole avec getSymbole
    // char symbole;

public :
    // Constructeurs
    Case(); // Case vide par défaut
    Case(Pion p);

    // des fonctions qui modifient le contenu de la Case
    // add/remove Pion

    // Affichage
    friend ostream& operator<<(ostream& out, Case c);

};

// Affichage
ostream& operator<<(ostream& out, Case c);
#endif
