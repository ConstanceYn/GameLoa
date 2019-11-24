#include <iostream>
#include "Plateau.hpp"

using namespace std;

int main()
{
    cout << "Game !" << endl;
    Plateau p {"assets/boards/testCreation.board"};
    cout << p ;
    return 0;
}
