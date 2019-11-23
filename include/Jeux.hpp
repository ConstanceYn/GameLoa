#ifndef JEUX
#define JEUX

#include "Plateau.hpp"
#include "Joueur.hpp"


using namespace std;

class Jeux {
private:
    // Réflechir à comment créer un ensemble de Plateau
    // Est ce que ça fonctionne par dossier ?
    //   Idée (bonne ou mauvaise je ne sais pas) : 1 sous dossier "dossier" de board = 1 jeux
    //                                           et les plateaux s'appelle "dossier_n" avec n le numero du niveau 
    vector<Plateau> plateaux;
    Joueur joueur;

public:
    Jeux ();
    //virtual ~Jeux ();
};


#endif
