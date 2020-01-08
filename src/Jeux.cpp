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
    if (niveau >= plateaux.size())
        cout << "Jeu terminé !!" << endl;
        cout << "BRAVO !!" << endl;
}


void Jeux::tour(char c)
{
    // Pour l'instant seulement le deplacement du joueur
    char res = plateaux[niveau].parseMouv(c);
    if (res == '$')
        joueur.addElement(1, 0);
    if (res == '*')
        joueur.addElement(0, 1);
    if (res == '+')
        nextLevel();
    if (c == 't' && joueur.getTp() >0)
    {
        plateaux[niveau].parseTp(c);
        joueur.addElement(0, -1); // on enlève un chargeur
    }
    // plateaux[niveau].parseMstr();
}




ostream& operator<<(ostream &out, Jeux j)
{
    out << j.joueur << endl;
    out << j.plateaux[j.niveau] << endl;

    return out;
}
