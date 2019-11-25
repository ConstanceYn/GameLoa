#ifndef PION
#define PION

#include <iostream>

using namespace std;

class Pion {
protected:
    int i;
    int j;
    char symbole;
    // on ne crée pas d'Pion autre que diamant et chargeur
    Pion (char c);

public:
    //virtual ~Pion ();
    char getSymbole();
    //virtual void actionPion();
    //      fonction qui fait ce que l'Pion fait

    // virtual bool move(int i, int j)
    //      regarde si un déplacement est valide
};


#endif
