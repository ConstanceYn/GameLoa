#include "Plateau.hpp"

Plateau::Plateau()
{
    ifstream fichier("assets/boards/test.board"); // ouverture en mode lecture
    // test.board a 10*7 cases
    char c;
    // si le fichier est bien ouvert
    if (fichier.is_open())
    {
        cout << "Pas prout cette fois" << endl;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                fichier.get(c);
                plateau.at(i).push_back(c);
            }
        }
    }

    // si le fichier n'est pas bien ouvert ce qui est actuellement le cas
    else
    {
        cout << "Prout" << endl;
    }
}

ostream &operator<<(ostream &out, Plateau p)
{
    for (int i = 0; i < p.plateau.size(); i++)
    {
        for (int j = 0; j < p.plateau.at(i).size(); j++)
        {
            out << p.plateau.at(i).at(j);
        }
    }
    return out;
}
