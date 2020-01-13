#ifndef MEGAMONSTRE
#define MEGAMONSTRE

#include "Monstre.hpp"

class MegaMonstre : public Monstre{
private:

public:
    MegaMonstre (int x, int y);
    //virtual ~Monstre ();

    //virtual void resetBouge();

    virtual bool moving(int x, int y, Plateau& p); // retourne si joueur manger
    virtual bool teleport(int x, int y, Plateau& p); // retourne si joueur manger
};


#endif
