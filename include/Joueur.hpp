#ifndef JOUEUR
#define JOUEUR

#include "Pion.hpp"


using namespace std;

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
