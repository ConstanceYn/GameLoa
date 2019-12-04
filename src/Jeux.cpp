#include "Jeux.hpp"


Jeux::Jeux(string str) : nom(str)
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

ostream& operator<<(ostream &out, Jeux j)
{
    for (size_t i = 0; i < j.plateaux.size(); i++)
    {
        out << j.plateaux[i];
        out << endl;
    }
    return out;
}
