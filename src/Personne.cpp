#include "Personne.hpp"

Personne::Personne(string str)
{
    string chemin = "assets/boards/";
    char c = '0';
    int val = 0;
    diam = 0;
    tp = 0;
    string setting = chemin + str +"/"+"setting";
    ifstream set (setting);
    if (set)
    {
        set.seekg(0, ios::end);
        int taille = set.tellg();
        set.seekg(0, ios::beg);
        while (c != '\n')
        {
            val = c - '0'; // conversion char to int
            diam = diam*10 + val;
            set.get(c);
        }
        set.get(c);
        while (c != '\n')
        {
            val = c - '0';
            tp = tp*10 + val;
            set.get(c);
        }
    }

}

void Personne::addElement(int d, int t)
{
    diam += d;
    tp += t;
}

int Personne::getTp() const
{
    return tp;
}
int Personne::getDiam() const
{
    return diam;
}

ostream& operator<<(ostream& out, Personne p)
{
    out << "Nombre de Diamant : " << p.diam << endl;
    out << "Nombre de Chargeur : " <<p.tp << endl;
    return out;
}

void teleport(){}
