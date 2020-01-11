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

void Jeux::free(){
    for (size_t i = 0; i < plateaux.size(); i++){
        plateaux[i].free();
    }
}

void Jeux::nextLevel()
{
    niveau += 1;
    if (niveau >= plateaux.size())
        cout << "Jeu terminé !!" << endl;
        cout << "BRAVO !!" << endl;
}


bool Jeux::tour(char c)
{
  bool b = false;
  if (c == 't' && joueur.getTp() >0)
  {
      plateaux[niveau].parseTp(c);
      joueur.addElement(0, -1); // on enlève un chargeur
      b = plateaux[niveau].parseMstr();
  }else{
      char res = plateaux[niveau].parseMouv(c);
      if (res == '$')
          joueur.addElement(1, 0);
      if (res == '*')
          joueur.addElement(0, 1);
      if (res == '+')
          nextLevel();
      if (res != 'y')
          b = plateaux[niveau].parseMstr();
  }
  if (b){
      cout << "Oh non ! Vous avez été mangé :'(\nGame over" << endl;
      return true;
  }
  return false;
}


ostream& operator<<(ostream &out, Jeux j)
{
    out << j.joueur << endl;
    out << j.plateaux[j.niveau] << endl;

    return out;
}
