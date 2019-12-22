#ifndef PORTE
#define PORTE

#include "Case.hpp"

//const Pion PORTEF = Pion('-');
//const Pion PORTEO = Pion('+');

class Porte : public Case {
private:
    bool ouverte;

public:
    Porte (int x, int y);
    void ouverture();
    //virtual ~Porte ();
};

#endif
