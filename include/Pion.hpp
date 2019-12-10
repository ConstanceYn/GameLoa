#ifndef PION
#define PION

#include <iostream>

using namespace std;

class Plateau;

class Pion {
protected:
    char symbole;
    int i;
    int j;

public:
    Pion(); // Pion vide
    Pion (char c);

    //virtual ~Pion ();

    // Getters
    char getSymbole();
    int getI();
    int getJ();

    //virtual void actionPion();
    //      fonction qui fait ce que le Pion fait

    //virtual bool move(int i, int j, Plateau p);
    //      regarde si un déplacement est valide
};


#endif
