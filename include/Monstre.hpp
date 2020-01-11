#ifndef MONSTRE
#define MONSTRE

#include "Pion.hpp"

class Monstre : public Pion{
private:
    bool bouge;
    bool diamant;
    bool chargeur;

public:
    Monstre (int x, int y);
    //virtual ~Monstre ();

    virtual void resetBouge();

    virtual bool moving(int x, int y, Plateau& p); // retourne si joueur manger
    virtual bool teleport(int x, int y, Plateau& p); // retourne si joueur manger
};


#endif
