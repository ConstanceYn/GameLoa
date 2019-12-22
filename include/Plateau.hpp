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

    // une référence pour avoir la case qu'on veut et pas juste une copie
    Case& getCase(const int i, const int j);
    //Pion& getJoueur() const;

    void parseMouv(char c);

    friend ostream& operator<<(ostream &out, Plateau p);
};

ostream& operator<<(ostream &out, Plateau p);

#endif
