#include "Plateau.hpp"


Plateau::Plateau(string chemin)
{
    ifstream fichier(chemin); // ouverture en mode lecture

    char c;
    // on récupère la taille du fcihier pour savoir quand on arrive à la fin
    fichier.seekg(0, ios::end);
    int taille = fichier.tellg();
    fichier.seekg(0, ios::beg);
    // si le fichier est ouvert
    if (fichier)
    {
        while(fichier.tellg() != taille)
        {
            vector<char> v;

            while(c!='\n')
            {
                fichier.get(c);
                if (c!='\n')
                    v.push_back(c);
            }
            c =' ';
            plateau.push_back(v);
        }
    }

    // si le fichier n'est pas bien ouvert ce qui est actuellement le cas
    // non, maintenant ça marche !!
    else
    {
        cout << "Prout" << endl;
    }
}

ostream &operator<<(ostream &out, Plateau p)
{
    for (int i = 0; i < p.plateau.size(); i++)
    {
        for (int j = 0; j < p.plateau[i].size(); j++)
            out << p.plateau[i][j];
        out << endl;
    }
    return out;
}
