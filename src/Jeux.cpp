#include "Jeux.hpp"


Jeux::Jeux(string str) : nom(str), joueur(Personne()), niveau(0)
{
    string chemin  = "assets/boards/";
    bool existe = true;
    int i = 1;
    while (existe)
    {
        string fichier = chemin + str + "/" +str +to_string(i)+".board";
        ifstream stream (fichier);
        if (stream)
        {
            stream.close();
            Plateau p {fichier};
            plateaux.push_back(p);
        }
        else
            existe = false;
        i++;
    }
}

void Jeux::nextLevel()
{
    niveau += 1;
    if (niveau > plateaux.size())
        cout << "Jeu terminé !!" << endl;
        cout << "BRAVO !!" << endl;
}


void Jeux::tour()
{
    // Pour l'instant seulement le deplacement du joueur
    char c;
    cout << "Mouvement :" << endl;
    cin >> c;
    plateaux[niveau].parseMouv(c);
}




ostream& operator<<(ostream &out, Jeux j)
{
    out << j.joueur << endl;
    out << j.plateaux[j.niveau] << endl;

    return out;
}
