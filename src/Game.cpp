#include <iostream>
#include "Jeux.hpp"

using namespace std;


int main(int argc, char const *argv[])
{
    cout << "Game !" << endl << endl;

    string nom = "testCreation";
    if (argc >= 2)
        nom = argv[1];

    Jeux j {nom};
    cout << j;

    char c;

    bool continuer = true;
    while(continuer)
    {
        cout << "Mouvement :" << endl;
        cin >> c;
        bool b = j.tour(c);
        cout << j;
        continuer = ((c != 'p') && !b);
    }
    j.free();
    return 0;
}
