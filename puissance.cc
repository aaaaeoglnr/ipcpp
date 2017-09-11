#include<iostream>
#include<array>
using namespace std;

enum Couleur {vide, rouge, jaune}; 
typedef array<array<Couleur, 7>, 6> Grille;



void initialise(Grille&);
void affiche(const Grille&);
bool joue(Grille&, size_t, Couleur);
void demande_et_joue(Grille&, Couleur);
bool est_ce_gagne(const Grille&, Couleur);
unsigned int compte(const Grille&, size_t, size_t, int, int);
bool plein(const Grille&);

int main()
{
	Grille grille;
	initialise(grille);
	affiche(grille);

	Couleur couleur_joueur(jaune);
	bool gagne(false);
	bool grille_plein(false);
	do{
		demande_et_joue(grille, couleur_joueur);
		affiche(grille);
		gagne = est_ce_gagne(grille, couleur_joueur);
		//on change la couleur pour la couleur de l'autre joueur
		couleur_joueur = (couleur_joueur == jaune? rouge : jaune);
		grille_plein = plein(grille);
	}while(not gagne and not grille_plein);
	
	if (grille_plein) {
			cout << endl << "Personne a gagne! " ;
	} else {
			cout << endl << "Le joueur ";
			cout << (couleur_joueur == jaune? "O" : "X") 
			<< " a gagne!"<<endl;
	}

	return 0;
}


void initialise(Grille& grille){
	for (auto &l:grille){
		for (auto &c:l){
			c = vide;
		}
	}
}

//affiche o pour un case rouge et x pour une case jaune
void affiche(const Grille& grille)
{
	for(auto l : grille){
		cout << " |";
		for (auto c : l){
			char couleur;
			switch(c){
				case vide: couleur = '_'; break;
				case rouge: couleur = 'O'; break;
				case jaune: couleur = 'X'; break;
			}
			cout << couleur << "|";
			
		}
		cout << endl;
	}
	
	cout << "=";
	for(size_t i(1); i <= grille[0].size(); i++) {
		cout << '=' << i;
	}
	cout << "==";
	cout << endl << endl;
}


bool joue(Grille& grille, size_t colonne, Couleur couleur) 
{
	if ((grille[0][colonne] != vide) or ( colonne > grille[0].size() - 1)) {
		return false;
	}
	//on parcourt la colonne en partant du bas
	size_t ligne(grille.size() - 1);
	while (grille[ligne][colonne] != vide) {
		--ligne;
	};
	//on remplit la case vide trouvee
	
	grille[ligne][colonne] = couleur;
	return true;
}

void demande_et_joue(Grille &grille, Couleur couleur_joueur)
{
	bool valide(false);
	do {
		cout << "Joueur "; 
		cout << (couleur_joueur == jaune? "X" : "O");
		cout << ": entrez un numero de colonne" << endl;
		size_t colonne;
		cin >> colonne;
		--colonne;
		valide = joue(grille, colonne, couleur_joueur);
		if (not valide) {
			cout << "Ce coup n'est pas valide" << endl;
		}
	} while (not valide);

}



bool est_ce_gagne(const Grille& grille, Couleur couleur)
{
	for(size_t ligne(0); ligne < grille.size(); ligne++) {
		for (size_t colonne(0); colonne < grille[ligne].size(); colonne++) {
			Couleur couleur_case(grille[ligne][colonne]);
			if (couleur_case == couleur) {
				const size_t ligne_max(grille.size() - 4);
				const size_t colonne_max(grille[ligne].size() - 4);
				if (	//en diagonalle, vers le haut et la droite
						(ligne >= 3 
					and colonne <= colonne_max
					and compte(grille, ligne, colonne, -1, 1) >= 4) 


       					//horizontalement, vers la droite
					or (colonne <= colonne_max
					and compte(grille, ligne, colonne, 0, 1) >= 4)

					//en diagonale, vers le bas et la droite
					or (ligne <= ligne_max and colonne <= colonne_max
					and compte(grille, ligne, colonne, 1, 1) >= 4)
			
				      	//verticalement, vers le bas
					or ( ligne <= ligne_max
						and compte(grille, ligne, colonne, 1, 0) >= 4)) {
		
					return true;
				}
			}
		}
	}
	return false;
}


unsigned int compte(const Grille& grille, size_t ligne_depart, size_t colonne_depart, int dir_ligne, int dir_colonne)
{
	unsigned int compteur(0);
	size_t ligne(ligne_depart);
	size_t	colonne(colonne_depart);

	while(ligne < grille.size() and colonne < grille[0].size() and 
			grille[ligne][colonne] 
			== grille[ligne_depart][colonne_depart]) {
		++compteur;
		ligne   += dir_ligne;
		colonne += dir_colonne;
	}
	return compteur;

}


bool plein(const Grille& grille)
{
		for(size_t j(0); j < grille[0].size(); j++) {
				if (grille[0][j] == vide) {
					return false;
				}
		}
		return true;
}
