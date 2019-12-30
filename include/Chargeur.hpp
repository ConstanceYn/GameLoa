#ifndef CHARGEUR
#define CHARGEUR

#include "Pion.hpp"

class Chargeur : public Pion {
private:
    // je sais pas

public:
    Chargeur (int x, int y);
    //virtual ~Chargeur ();

    void actionPion(Personne p);

};


#endif
