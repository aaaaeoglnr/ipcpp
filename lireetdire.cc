#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
  int dix(1);
  int temp(nombre);
  while (temp >= 10) {
    dix  *= 10;
    temp /= 10;
  }
  nombre %= dix;
  return temp;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
	nombre *= 10;
	nombre += chiffre;
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{
	ajouter_chiffre_droit(nombre, repetitions_chiffre);
	ajouter_chiffre_droit(nombre, chiffre);
}

int lire_et_dire(int nombre)
{
	int nouveau_nombre(0);
	if (nombre < 10){
		dire_chiffre(nouveau_nombre, 1, nombre);
	} else {
		int chiffre = separer_chiffre_gauche(nombre);
		int nouvelle_chiffre = separer_chiffre_gauche(nombre);
		int chiffre_i = 1;
		while(nombre > 0){
			if (nouvelle_chiffre == chiffre){
				chiffre_i++;
			} else {
				dire_chiffre(nouveau_nombre, chiffre_i, chiffre);
				chiffre_i = 1;
				chiffre = nouvelle_chiffre;
			}
			nouvelle_chiffre = separer_chiffre_gauche(nombre);
		}
		if (chiffre == nouvelle_chiffre){
			chiffre_i++;
			dire_chiffre(nouveau_nombre, chiffre_i, chiffre);
		} else {
			dire_chiffre(nouveau_nombre, chiffre_i, chiffre);
			dire_chiffre(nouveau_nombre, 1, nouvelle_chiffre);
		}
	}
	return nouveau_nombre;
}	

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
  while (fois-- > 0) {
    nombre = lire_et_dire(nombre);
  }
}

int main()
{
  int nombre(1);
  int fois(1);
  cin >> nombre >> fois;
  repeter_lire_et_dire(nombre, fois);
  cout << nombre << endl;
  return 0;
}
