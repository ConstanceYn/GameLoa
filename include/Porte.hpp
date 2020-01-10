#ifndef PORTE
#define PORTE

#include "Pion.hpp"

//const Pion PORTEF = Pion('-');
//const Pion PORTEO = Pion('+');

class Porte : public Pion {
private:
    bool ouverte;

public:
    Porte (int x, int y);
    //virtual ~Porte ();
    virtual void ouverture(); // ouvre la porte
};

#endif
