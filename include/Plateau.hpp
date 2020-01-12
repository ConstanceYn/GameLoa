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
    vector<vector<Pion*>> plateau;

public:
    Plateau (string chemin);
    //virtual ~Plateau ();

    void free();

    int sizeI();

    int sizeJ();

    // une référence pour avoir la case qu'on veut et pas juste une copie
    Pion * getCase(const int i, const int j);
    void setCase(const int i, const int j, Pion * p);

    char parseMouv(char c); // déplacement du joueur
    bool parsePorte(); // ouverture d'une porte
    bool parseTp(char c); // téléportation
    bool parseMstr(); // déplacement des monstres

    void copie(string str);

    friend ostream& operator<<(ostream &out, Plateau p);
};

ostream& operator<<(ostream &out, Plateau p);

#endif
