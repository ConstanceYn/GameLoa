#ifndef CASE
#define CASE

#include "Pion.hpp"

//const Pion VIDE = Pion();

class Case {
protected :
    Pion * pion; // Pion "vide" si aucun
    // On récupère le symbole avec getSymbole
    // char symbole;


    /* Objet objet; */

public :
    // Constructeurs
    Case(int x, int y); // Case vide par défaut
    Case(Pion * p);


    // Getter
    Pion getPion();
    Pion * getPionPointeur();

    // add/remove Pion
    void addPion(Pion p);
    void removePion();


    /*
     Case(Objet o);
    Objet &getObjet();
    void addObjet(const Objet& o);
    */


    // Affichage
    friend ostream& operator<<(ostream& out, Case c);

};

// Affichage
ostream& operator<<(ostream& out, Case c);
#endif
