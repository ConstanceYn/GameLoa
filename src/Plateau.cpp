#include "Plateau.hpp"

Plateau::Plateau()
{
    ifstream fichier("assets/boards/test.board"); // ouverture en mode lecture
    // test.board a 10*7 cases
    char c;

    // si le fichier est bien ouvert
    if (fichier)
    {
        for (int i = 0; i < 7; i++)
        {
            vector<char> v;
            // 10 cases + 1 retour à la ligne
            for (int j = 0; j < 11; j++)
            {
                fichier.get(c);
                v.push_back(c);
            }
            plateau.push_back(v);
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
