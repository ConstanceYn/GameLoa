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

};

#endif
