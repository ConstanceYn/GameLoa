#ifndef PION
#define PION

#include <iostream>

using namespace std;

class Pion {
protected:
    //int i;
    //int j;
    char symbole;
    // on ne crée pas de Pion autre que diamant et chargeur
    // Hein ?

public:
    // Constructeurs (ils étaient en protected, je ne suis pas sur pourquoi ?)
    Pion(); // Pion vide
    Pion (char c);

    //virtual ~Pion ();

    // Getters
    char getSymbole();

    //virtual void actionPion();
    //      fonction qui fait ce que le Pion fait

    // virtual bool move(int i, int j)
    //      regarde si un déplacement est valide
};


#endif
