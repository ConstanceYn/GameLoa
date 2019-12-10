#ifndef JOUEUR
#define JOUEUR

#include "Pion.hpp"

class Joueur : public Pion{
private:
    int nbDiam;
    bool sortie;
    int nbTp;

public:
    Joueur ();
    //virtual ~Joueur ();

    bool move(int x, int y, Plateau p);
    bool moving(int x, int y, Plateau p);
    
};

#endif
