#ifndef JOUEUR
#define JOUEUR

#include "Pion.hpp"

class Joueur : public Pion{
private:
    //bool sortie;

public:
    Joueur (int x, int y);
    // quand on crée un joueur qui a déja des tp en stock
    // je ne sais pas si ça servira un jour
    //Joueur(int x, int y, int t);
    //virtual ~Joueur ();

    virtual bool moving(const int x, const int y, Plateau& p);
    virtual bool teleport(int x, int y, Plateau &p); // fonctionne pas pour l'instant

    //bool getSortie() const;
};

#endif
