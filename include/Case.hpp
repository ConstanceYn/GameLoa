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

    // Getter
    const Pion& getPion() const;

    // add/remove Pion
    void addPion(const Pion p);
    void removePion();

    // des fonctions qui modifient le contenu de la Case

    // Affichage
    friend ostream& operator<<(ostream& out, Case c);

};

// Affichage
ostream& operator<<(ostream& out, Case c);
#endif
