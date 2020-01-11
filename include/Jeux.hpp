#ifndef JEUX
#define JEUX

#include <string>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include "Plateau.hpp"
#include "Personne.hpp"

using namespace std;

class Jeux {
private:
    // 1 sous dossier "dossier" de board = 1 jeux
    //      et les plateaux s'appelle "dossiern" avec n le numero du niveau
    string nom;
    Personne joueur;
    vector<Plateau> plateaux;
    // le niveau dans lequel on est actuellement
    int niveau;

public:
    Jeux (string str);
    //virtual ~Jeux ();
    void free();
    void nextLevel();
    bool tour(char c);
    bool save();

    friend ostream& operator<<(ostream &out, Jeux j);
};

ostream& operator<<(ostream &out, Jeux j);


#endif
