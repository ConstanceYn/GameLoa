#ifndef PLATEAU
#define PLATEAU

#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


class Plateau {
private:
    vector<vector<char>> plateau;
    // char pour l'instant, on modifiera plus tard en Case

public:
    Plateau (string chemin);
    //virtual ~Plateau ();
    friend ostream& operator<<(ostream &out, Plateau p);
};

ostream& operator<<(ostream &out, Plateau p);

#endif
