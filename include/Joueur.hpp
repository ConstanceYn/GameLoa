#ifndef JOUEUR
#define JOUEUR

#include "Pion.hpp"

class Joueur : public Pion{
private:
    int nbDiam;
    bool sortie;
    //int nbTp;

public:
    Joueur (int x, int y);
    // quand on crée un joueur qui a déja des tp en stock
    // je ne sais pas si ça servira un jour
    Joueur(int x, int y, int t);
    //virtual ~Joueur ();

    // ajoute un diam à nbDiam et modifie sortie
    void addDiam();
    //ajoute un chargeur
    //void addTp();
    //void setTp(int t);
    virtual void teleport(int x, int y, Plateau &p); // fonctionne pas pour l'instant

    bool getSortie() const;
};

#endif
