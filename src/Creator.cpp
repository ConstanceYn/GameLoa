#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// affiche un plateau de char
//      plus tard : on aura un plateau de case donc on utilisera la fonction d'affichage de Plateau
void afficher(vector<vector<char>> v);


// crée un fichier plateau à partir des entrées consoles
void newPlateau();
void newFile(vector<vector<char>> v);
char parse(int n);


int main()
{
    cout << "Creation !" << endl;
    cout << endl;
    newPlateau();
    return 0;
}



void afficher(vector<vector<char>> v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j < v[i].size(); j++)
            cout << v[i][j];
        cout << endl;
    }
}

void newPlateau()
{
    int x;
    int y;
    cout << "Quelles dimensions voulez vous pour le nouveau plateau ?" << endl;
    cout << "largeur = " ;
    cin >> x;
    cout << "hauteur = ";
    cin >> y;

    // creation des fondations avec pose des murs porteurs
    vector<vector<char>> p;
    for (int i = 0; i < y; i++)
    {
        vector<char> v;
        for (int j = 0; j < x; j++)
        {
            if (i== 0 || i== (y-1) || j==0 || j==(x-1) )
            v.push_back('X');
            else
            v.push_back(' ');
        }
        p.push_back(v);
    }
    afficher(p);

    bool continuer = true;
    int choix;
    int i;
    int j;
    char c;
    // décoration intérieur
    while (continuer)
    {
        // /!\ ATTENTION aucun controle n'est fait, donc on peut rentrer de la merde !!!!
        cout << "Que voulez vous ajouter ? (Entrez un nombre)" << endl;
        cout << "1- une porte" << endl;
        cout << "2- un monstre" << endl;
        cout << "3- un mur" << endl;
        cout << "4- un diamant (d'innocence)" << endl;
        cout << "5- un chargeur" << endl;
        cin >> choix;
        char symbole = parse(choix);
        cout << "À quel endroit ?" << endl;
        cout << "abscisse (0 à "<< x-1 <<") = ";
        cin >> i;
        cout << "ordonnée (0 à "<< y-1 <<") = ";
        cin >> j;
        p[j][i] = symbole;
        afficher(p);
        cout << "Voulez vous continuer de modifier le plateau ? (o/n) ";
        cin >> c;
        continuer = (c == 'o');
    }
    newFile(p);
}

char parse(int n)
{
    switch (n) {
        case 1: return '-';
        case 2: return 'm';
        case 3: return 'X';
        case 4: return '$';
        case 5: return '*';
        default: return ' ';
    }
}

void newFile(vector<vector<char>> v)
{
    ofstream fichier ("assets/boards/testCreation.board");

    if (fichier)
    {
        for (size_t i = 0; i < v.size(); i++)
        {
            for (size_t j = 0; j < v[i].size(); j++)
                fichier << v[i][j];
            fichier << endl;
        }
    }
    else
        cout << "prout" << endl;
}
