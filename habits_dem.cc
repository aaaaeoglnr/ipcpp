#include<iostream>
#include<string>
#include<memory>

using namespace std;

struct Maison {
	string addresse;
};

struct Personne
{
	string nom;
	Maison* maison;
};

void affiche(Personne);

int main()
{
	Maison maison1({"Kasteelstraat, 1"});
	Maison maison2({"Mechelenweeg, 43"});
	Maison* m1(&maison1);
	Maison* m2(&maison2);
	Personne voisin1 ({"Veerle Peeters", m2});
	Personne voisin2 ({"Mieke Janssen", m1});
	Personne voisin3 ({"Jan Peeters", m2});
	Personne voisin4 ({"Shannon Janssen", m1});
	Personne voisin5 ({"Veerle Janssen", m1});
	Personne voisin6 ({"Peter Janssen", m1});
	
	affiche(voisin1);
	affiche(voisin3);
	affiche(voisin2);
	affiche(voisin4);
	affiche(voisin5);
	affiche(voisin6);

	voisin6.maison = m2; 
	cout <<endl;
	affiche(voisin6);
	
	affiche(voisin1);
	affiche(voisin3);
	affiche(voisin2);
	affiche(voisin4);
	affiche(voisin5);
	affiche(voisin6);

	return 0;	
}

void affiche(Personne p)
{
	cout << endl << p.nom << " habite " << p.maison->addresse << endl;
}
