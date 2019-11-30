#include <iostream>
#include "Plateau.hpp"

using namespace std;


int main(int argc, char const *argv[])
{
    cout << "Game !" << endl;
    string nom = "assets/boards/";
    if (argc >= 2)
    {
        nom += argv[1];
        nom +=".board";
    }
    else
        nom += "testCreation.board";
    Plateau p {nom};
    cout << p ;
    return 0;
}
