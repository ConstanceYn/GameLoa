#ifndef MONSTRENUL
#define MONSTRENUL

#include "Monstre.hpp"

class MonstreNul : public Monstre{
private:

public:
    MonstreNul (int x, int y);
    //virtual ~Monstre ();

    //virtual void resetBouge();

    //virtual bool moving(int x, int y, Plateau& p); // retourne si joueur manger
    virtual bool teleport(int x, int y, Plateau& p); // retourne si joueur manger
};


#endif
