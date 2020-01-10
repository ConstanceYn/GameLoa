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
        int i = 0;
        int j = 0;
        while(fichier.tellg() != taille)
        {
            vector<Pion*> v;
            i = 0;
            while(c!='\n')
            {
                fichier.get(c);
                switch(c)
                {
                  case ' ': // vide
                    v.push_back(new Pion(' ',i,j));
                    break;

                  case 'X': // mur
                    v.push_back(new Mur(i,j));
                    break;

                  case '-': // porte
                    v.push_back(new Porte(i,j));
                    break;

                  case '$': // diamant
                    v.push_back(new Diamant(i,j));
                    break;

                  case '*': // chargeur
                    v.push_back(new Chargeur(i,j));
                    break;

                  case 'J': // joueur
                    v.push_back(new Joueur(i,j));
                    break;

                  case 'm' : // monstre
                    v.push_back(new Monstre(i,j));
                    break;

                  default :
                    break;
                }
                i++;
            }
            c =' ';
            plateau.push_back(v);
            j++;
        }
    }
    else
    {
        cout << "Prout" << endl;
    }
}

int Plateau::sizeI()
{
  return plateau[0].size();
}

int Plateau::sizeJ()
{
  return plateau.size();
}

Pion * Plateau::getCase(const int i, const int j)
{
  return plateau[j][i];
}

void Plateau::setCase(const int i, const int j, Pion * p)
{
    plateau[j][i] = p;
}

char Plateau::parseMouv(char c)
{
    int x = 0, y = 0;
    switch (c)
    {
        case 'a': // en haut à gauche
            x = -1;
            y = -1;
            break;
        case 'z': // en haut au milieu
            y = -1;
            break;
        case 'e': // en haut à droite
            x = 1;
            y = -1;
            break;
        case 'q': // à gauche
            x = -1;
            break;
        case 'd': // à droite
            x = 1;
            break;
        case 'w': // en bas à gauche
            x = -1;
            y = 1;
            break;
        case 'x': // en bas au milieu
            y = 1;
            break;
        case 'c' : // en bas à droite
            x = 1;
            y = 1;
            break;
        default:
            break;
    }

    for (size_t i = 0; i < plateau.size(); i++) { // i est la hauteur !!
        for (size_t j = 0; j < plateau[i].size(); j++) { // j est la largeur !!
            if (plateau[i][j]->getSymbole()== 'J')
            {
                int a = j + x;
                int b = i + y;
                char res = plateau[b][a]->getSymbole();
                plateau[i][j]->moving(a, b, *this);
                return res;
            }
        }
    }
    return (' ');
}

bool Plateau::parsePorte()
{
    for (size_t i = 0; i < plateau.size(); i++) { // i est la hauteur !!
        for (size_t j = 0; j < plateau[i].size(); j++) { // j est la largeur !!
            if (plateau[i][j]->getSymbole()== '-')
            {
                plateau[i][j]->ouverture();
                return true;
            }
        }
    }
    return false;
}

bool Plateau::parseTp(char c)
{
    for (size_t i = 0; i < plateau.size(); i++) { // i est la hauteur !!
        for (size_t j = 0; j < plateau[i].size(); j++) { // j est la largeur !!
            if (plateau[i][j]->getSymbole()== 'J')
            {
                srand(time(NULL));
                int x = rand()%plateau[0].size();
                srand(time(NULL));
                int y = rand()%plateau.size();

                plateau[i][j]->teleport(x, y, *this);

                return true;
            }
        }
    }
    return false;
}

void Plateau::parseMstr()
{
    for (size_t i = 0; i < plateau.size(); i++) { // i est la hauteur !!
        for (size_t j = 0; j < plateau[i].size(); j++) { // j est la largeur !!
            if (plateau[i][j]->getSymbole()== 'm') {
                cout << i << endl;
                cout << j << endl;
                plateau[i][j]->teleport(i, j, *this);
            }
        }
    }
}

ostream &operator<<(ostream &out, Plateau p)
{
    for (int i = 0; i < p.plateau.size(); i++)
    {
        for (int j = 0; j < p.plateau[i].size(); j++)
            out << p.plateau[i][j]->getSymbole();
        out << endl;
    }
    return out;
}
