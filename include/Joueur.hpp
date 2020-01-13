#ifndef JOUEUR
#define JOUEUR

#include "Pion.hpp"

class Joueur : public Pion{
private:
    //bool sortie;

public:
    Joueur (int x, int y);
    //virtual ~Joueur ();

    virtual bool moving(const int x, const int y, Plateau& p);
    virtual bool teleport(int x, int y, Plateau &p); 
};

#endif
