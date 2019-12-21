#ifndef JEUX
#define JEUX

#include <string>
#include "Plateau.hpp"
#include "Joueur.hpp"

using namespace std;

class Jeux {
private:
    // 1 sous dossier "dossier" de board = 1 jeux
    //      et les plateaux s'appelle "dossiern" avec n le numero du niveau
    string nom;
    Personne joueur;
    vector<Plateau> plateaux;

public:
    Jeux (string str);
    //virtual ~Jeux ();
    friend ostream& operator<<(ostream &out, Jeux j);
};

ostream& operator<<(ostream &out, Jeux j);


#endif
