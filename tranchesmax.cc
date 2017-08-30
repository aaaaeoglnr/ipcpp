#include<iostream>
#include<vector>
using namespace std;

int somme_consecutifs_max(vector<int>);
vector<size_t> lignes_max(vector<vector<int>>);
vector<vector<int>> tranches_max(vector<vector<int>>);

int main()
{
	return 0;
}

int somme_consecutifs_max(vector<int> ligne)
{
	int max(0), somme(0);
	int longueur = ligne.size();
	for (int i(0); i < longueur; i++) {
		if (ligne[i] != 0){
			somme += ligne[i];
		} else {
			if (somme > max) {max = somme;}
			somme = 0;
		}
	}
	if (somme > max) {max = somme;}
	return max;
}

vector<size_t> lignes_max(vector<vector<int>> m)
{
	vector<size_t> lignes;
	int max(0);
	for (int i(0); i < m.size(); i++) {
		int somme = somme_consecutifs_max(m[i]);
		if (somme > max){
			max = somme;
			lignes.clear();
			lignes.push_back(i);
		} else if (somme == max){
			lignes.push_back(i);
		}
	}
	return lignes;
}

vector<vector<int>> tranches_max(vector<vector<int>> m)
{
	vector<vector<int>> tranche;

	vector<size_t> tranches = lignes_max(m);
	if (!tranches.empty()) {

		for (int i(0); i < tranches.size(); i++) {
			tranche.push_back(m[tranches[i]]);
		}
	}
	return tranche;
}
