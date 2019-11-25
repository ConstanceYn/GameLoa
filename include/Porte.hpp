#ifndef PORTE
#define PORTE

#include "Case.hpp"

class Porte : public Case {
private:
    bool ouverte;

public:
    Porte ();
    void ouverture();
    //virtual ~Porte ();
};

#endif
