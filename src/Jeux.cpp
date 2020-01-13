#include "Jeux.hpp"


Jeux::Jeux(string str) : nom(str), joueur(Personne(str)), niveau(0)
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

void Jeux::free(){
    for (size_t i = 0; i < plateaux.size(); i++){
        plateaux[i].free();
    }
}

bool Jeux::nextLevel()
{
    niveau += 1;
    if (niveau >= plateaux.size())
    {
        cout << "Jeu terminé !!" << endl;
        cout << "BRAVO !!" << endl;
        return true;
    }
    return false;

}


bool Jeux::tour(char c)
{
    if (c == 'j')
        return (save());
    bool b = false;
    if (c == 't' && joueur.getTp() >0)
    {
        plateaux[niveau].parseTp(c);
        joueur.addElement(0, -1); // on enlève un chargeur
        b = plateaux[niveau].parseMstr();
    }
    else
    {
        char res = plateaux[niveau].parseMouv(c);
        if (res == '$')
            joueur.addElement(1, 0);
        if (res == '*')
            joueur.addElement(0, 1);
        if (res == '+')
            return nextLevel();
        if (res != 'y')
            b = plateaux[niveau].parseMstr();
    }
    if (b){
        cout << "Oh non ! Vous avez été mangé :'(\nGame over" << endl;
        return true;
    }
    return false;
}

bool Jeux::save()
{
    string chemin = "assets/boards/";
    string nom;
    cout << "Entrez un nom pour votre sauvegarde : "<< endl;
    cin >> nom;
    chemin += nom;

    char* name = &chemin[0];
    mkdir(name, 0777);

    string setting = chemin + "/setting";
    ofstream set (setting);
    if (set)
    {
        set << to_string(joueur.getDiam());
        set << '\n';
        set << to_string(joueur.getTp());
        set << '\n';
    }

    for (int i = niveau; i < plateaux.size(); i++) {
        string str = chemin + "/" + nom + to_string(i-niveau +1)+ ".board";
        plateaux[i].copie(str);
    }


    return true;

}


ostream& operator<<(ostream &out, Jeux j)
{
    out << j.joueur << endl;
    out << j.plateaux[j.niveau] << endl;

    return out;
}
