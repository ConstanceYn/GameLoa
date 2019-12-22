#include <iostream>
#include "Jeux.hpp"

using namespace std;


int main(int argc, char const *argv[])
{
    cout << "Pour les lignes juste au dessus, voir les constructeurs dans Pion.cpp" << endl << endl;
    cout << "Game !" << endl << endl;

    string nom = "testCreation";
    if (argc >= 2)
        nom = argv[1];

    Jeux j {nom};
    cout << j;
    j.tour();
    cout << j;
    return 0;
}
