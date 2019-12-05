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
            vector<Case> v;

            while(c!='\n')
            {
                fichier.get(c);
                Case cas;
                switch(c)
                {
                  case ' ': // vide
                    cas = Case();
                    v.push_back(cas);
                    break;

                  case 'X': // mur
                    cas = Mur();
                    v.push_back(cas);
                    break;

                  case '-': // porte
                    cas = Porte();
                    v.push_back(cas);
                    break;

                  case '$': // diamant
                    cas = Case(Diamant());
                    v.push_back(cas);
                    break;

                  case '*': // chargeur
                    cas = Case(Chargeur());
                    v.push_back(cas);
                    break;

                  case 'J': // joueur
                    cas = Case(Joueur());
                    v.push_back(cas);
                    break;

                  case 'm' : // monstre
                    cas = Case(Monstre());
                    v.push_back(cas);
                    break;

                  default :
                    break;
                }
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
