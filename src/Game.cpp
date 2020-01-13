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
    
    char c;
    bool continuer = true;
    while(continuer)
    {
        cout << j;
        cout << "Mouvement :" << endl;
        cin >> c;
        bool b = j.tour(c);
        continuer = ((c != 'p') && !b);
    }
    j.free();
    return 0;
}
