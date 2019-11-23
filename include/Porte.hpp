#ifndef PORTE
#define PORTE

#include "Case.hpp"

using namespace std;

class Porte : public Case {
private:
    bool ouverte;

public:
    Porte ();
    void ouverture();
    //virtual ~Porte ();
};

#endif
