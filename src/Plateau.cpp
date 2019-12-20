#include "Plateau.hpp"


Plateau::Plateau(string chemin)
{
    ifstream fichier(chemin); // ouverture en mode lecture

    // si le fichier est ouvert
    if (fichier)
    {
        char c;
        // on récupère la taille du fcihier pour savoir quand on arrive à la fin
        fichier.seekg(0, ios::end);
        int taille = fichier.tellg();
        fichier.seekg(0, ios::beg);

        while(fichier.tellg() != taille)
        {
            vector<Case> v;

            while(c!='\n')
            {
                fichier.get(c);
                switch(c)
                {
                  case ' ': // vide
                    v.push_back(Case());
                    break;

                  case 'X': // mur
                    v.push_back(Mur());
                    break;

                  case '-': // porte
                    v.push_back(Porte());
                    break;

                  case '$': // diamant
                    v.push_back(Diamant());
                    break;

                  case '*': // chargeur
                    v.push_back(Chargeur());
                    break;

                  case 'J': // joueur
                    v.push_back(Joueur());
                    break;

                  case 'm' : // monstre
                    v.push_back(Monstre());
                    break;

                  default :
                    break;
                }
            }
            c =' ';
            plateau.push_back(v);
        }
    }

    else
    {
        cout << "Prout" << endl;
    }
}

Case Plateau::getCase(int i, int j) const{
  return plateau[i][j];
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
