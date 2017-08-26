#include <iostream>
using namespace std;

int main()
{
  cout << "Donnez l'heure de début de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
	if ((debut < 0) or (debut > 24) or (fin < 0) or (fin > 24))  
    cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
    else if (debut == fin)
    cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" 
    << endl;
    else if (debut > fin)
    cout << "Bizarre, le début de la location est après la fin ..." 
    << endl;
    else{
			int heures1 = fin - debut; 
			int heures2=0;  
			if (fin > 7){ 
				if (fin < 17) { 
					if (debut < 7){
						heures2 = fin - 7;				
					} else {
						heures2 = fin - debut;
					}
				} else if (debut < 7) {
					heures2 = 17-7;
				} else if (debut < 17){
						heures2 = 17 - debut;
				} 
			heures1 -= heures2;
			} 
		int total = heures1 * 1 + heures2 * 2;
		cout << "Vous avez loué votre vélo pendant" << endl;
		if (heures1){
			cout << heures1;
			cout << " heure(s) au tarif horaire de 1 franc(s)" << endl;
		}
		if (heures2){
			cout << heures2;
			cout << " heure(s) au tarif horaire de 2 franc(s)" << endl;
		}
		cout << "Le montant total à payer est de "
         << total << " franc(s)." << endl;
	}
  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
