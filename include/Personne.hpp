#ifndef PERSONNE
#define PERSONNE

#include <iostream>

using namespace std;

class Personne {
private:
    int diam;
    int tp;


public:
    Personne ();
    //virtual ~Personne ();

    // Pour ajouter ou enlever (-1) un diamant ou un tp
    void addPion(int d, int t);
    int getTp() const;

    friend ostream& operator<<(ostream& out, Personne p);
};

ostream& operator<<(ostream& out, Personne p);

#endif
