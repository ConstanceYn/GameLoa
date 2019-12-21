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
    bool move(const int x, const int y, const Plateau p);

public:
    Pion(); // Pion vide
    Pion (char c);

    //virtual ~Pion ();

    // Getters
    char getSymbole() const;
    int getI() const;
    int getJ() const;


    bool moving(const int x, const int y, Plateau &p);

    //virtual void actionPion();
    //      fonction qui fait ce que le Pion fait
    // par exemple l'action d'un monstre est de bouger

};


#endif
