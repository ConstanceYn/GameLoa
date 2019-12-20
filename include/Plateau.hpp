#ifndef PLATEAU
#define PLATEAU

#include <vector>
#include <fstream>

// je sais pas si il y a moyen de faire un include plus général
#include "Mur.hpp"
#include "Porte.hpp"
#include "Diamant.hpp"
#include "Chargeur.hpp"
#include "Joueur.hpp"
#include "Monstre.hpp"

using namespace std;

class Plateau {
private:
    vector<vector<Case>> plateau;

public:
    Plateau (string chemin);
    //virtual ~Plateau ();

    Case getCase(int i, int j) const;

    friend ostream& operator<<(ostream &out, Plateau p);
};

ostream& operator<<(ostream &out, Plateau p);

#endif
