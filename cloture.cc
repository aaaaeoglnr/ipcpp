#include <iostream>
#include <vector>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/


typedef vector<vector<int>> Carte;
struct Position{
	int i;
	int j;
};

bool binaire(Carte const& carte){
	for (auto l : carte){
		for (auto c : l) {
			if ((c != 0) and (c != 1)) {
				return false;
			}
		}
	}
	return true;
}

void affiche(Carte const& carte)
{
	for (auto l : carte) {
		for (auto c : l) {
			cout << c;
		}
		cout << endl;
	}
	cout << endl << "----" << endl;
}

bool existe(vector<int>, int);
void trouve_composantes_ext(Carte, vector<int>&);

void effacer_etangs(Carte& carte)
{
	vector<int> labels_bords;
	trouve_composantes_ext(carte, labels_bords);
	for(int i(0); i < carte.size(); i++) {
		for (int j(0); j < carte[0].size(); j++) {
			if ((carte[i][j] != 1) and 
			(!existe(labels_bords, carte[i][j])))  {
				carte[i][j] = 1;
			}
		}
	}

}

bool convexite_lignes(Carte& carte);

bool verifie_et_modifie(Carte& carte)
{
	if (!binaire(carte)){
		cout << "Votre carte du terrain ne contient pas que des 0 et des 1." << endl;
		return false;
	}
	if (!convexite_lignes(carte)) {
		return false;
	}
	effacer_etangs(carte);
	return true;;
}

double longueur_cloture(Carte const& carte, double echelle = 2.5)
{
	int unites(0);
	int lignes = carte.size();
	int collonnes = carte[0].size();
	for (int i(0); i < lignes; i++) {
		for (int j(0); j < collonnes; j++){
			if (carte[i][j] == 1) {
				if (i == 0) {unites++;}
				if (i == lignes - 1) {unites++;}
				if ((i != 0) and (carte[i - 1][j] != 1)) {unites++;}
				if ((i != lignes - 1) and (carte[i + 1][j] != 1)) {
					unites ++;
				}
				if (j == 0) {unites++;}
				if (j == collonnes - 1) {unites++;}
				if ((j != 0) and (carte[i][j - 1] != 1)) {unites++;}
				if ((j != collonnes - 1) and (carte[i][j +1] != 1)) {
					unites ++;
				}
					
			}
		}
	}	
	return unites * echelle;
}



void ajoute_unique(vector<int>& ensemble, int valeur)
{
	for (int i(0); i < ensemble.size(); i ++) {
		if (ensemble[i] == valeur) {
			return;
		}
	}
	ensemble.push_back(valeur);
}

void trouve_composantes_ext(Carte carte, vector<int>& labels_bords)
{
	int lignes = carte.size();
	int collonnes = carte[0].size();
	for (int i(0); i < lignes; i++) {
		if (carte[i][0] != 1) {
			ajoute_unique(labels_bords, carte[i][0]);
		}
		if (carte[i][collonnes - 1] != 1) {
			ajoute_unique(labels_bords, carte[i][collonnes - 1]);
		}
	}
	for(int j(1); j < collonnes - 1; j++) {
		if (carte[0][j] != 1) {
			ajoute_unique(labels_bords, carte[0][j]);
		}
		if (carte[lignes - 1][j] != 1) {
			ajoute_unique(labels_bords, carte[lignes - 1][j]);
		}
	}
}


bool existe(vector<int> ensemble, int valeur)
{
	for (int i(0); i < ensemble.size(); i++) {
		if (ensemble[i] == valeur) {
			return true;
		}
	}
	return false;
}


bool convexite_lignes(Carte& carte, vector<int> const& labels_bords)
{
	for (int i(0); i < carte.size(); i++) {
		bool bord_passe = false;
		bool trouve = false;
		int i_entrant(-1), j_entrant(-1);
		bool position_trouvee = false;
		for (int j(0); j < carte[0].size(); j++) {
			if ((carte[i][j] == 1) and !bord_passe) {
				bord_passe = true;
			}
			if ((carte[i][j] != 1) and (bord_passe)) {
				trouve = true;
				if (existe(labels_bords, carte[i][j]) 
				and !position_trouvee){
					i_entrant = i;
					j_entrant = j;
					position_trouvee = true;
				}				
			}
			if ((carte[i][j] == 1) and bord_passe and trouve 
			and (i_entrant != -1)){
		       		cout << "Votre carte du terrain n'est pas convexe "
		       		<<"par lignes :" << endl;
		      		cout << "bord extérieur entrant trouvé en position"
		      		<<" [" << i_entrant;
		      		cout << "][" << j_entrant;
		      		cout << "]" << endl;
				return false;
			}
			

		}
	}
	return true;
}

void marque_composantes(Carte&);

bool convexite_lignes(Carte& carte)
{
	 marque_composantes(carte);
	 vector<int> labels_bords;
	 trouve_composantes_ext(carte, labels_bords); 
	 return convexite_lignes(carte, labels_bords);
	
}


void marque_composantes(Carte& carte)
{
	vector<Position> p;
	int composante(1);
	for (int i(0); i < carte.size(); i++){
		for (int j(0); j < carte[i].size(); j++) {
			if (carte[i][j] == 0) {
				composante ++;
				Position pc = {i, j};
				p.push_back(pc);
				while (!p.empty()) {
					Position position_c = p.back();
					p.pop_back();
					int pci = position_c.i;
					int pcj = position_c.j;
					carte[pci][pcj] = composante;
					if ((pci > 0) and (carte[pci - 1][pcj] == 0)) {
							Position nord = {pci - 1, pcj};
							p.push_back(nord);
					}
					if ((pci < carte.size() - 1) and (carte[pci + 1][pcj] == 0)) {
						Position sud = {pci + 1, pcj};
						p.push_back(sud);
					}
					if ((pcj > 0) and (carte[pci][pcj - 1] == 0)) {
						Position est = {pci, pcj - 1};
						p.push_back(est);	
					}

					if ((pcj < carte[0].size() - 1) 
					and (carte[pci][pcj + 1] == 0)) {
							Position ouest = {pci, pcj + 1};
							p.push_back(ouest);
					}
				}
			}
		}
	}
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Carte carte = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };

  cout << "Carte au départ :" << endl;
  affiche(carte);
  if (verifie_et_modifie(carte)) {
    cout << "Carte après modification :" << endl;
    affiche(carte);
    cout << "Il vous faut " << longueur_cloture(carte)
         << " mètres de clôture pour votre terrain."
         << endl;
  }

  return 0;
}
