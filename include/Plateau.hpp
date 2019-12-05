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
    // char pour l'instant, on modifiera plus tard en Case -> Let's go !

public:
    Plateau (string chemin);
    //virtual ~Plateau ();
    friend ostream& operator<<(ostream &out, Plateau p);
};

ostream& operator<<(ostream &out, Plateau p);

#endif
