#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
  // Réduire le format d'affichage
  cout << setprecision(4);

  // Paramètres
  double taux_croissance_lapins(0.3);
  double taux_attaque(0.01);
  double taux_croissance_renards(0.008);
  double taux_mortalite(0.1);
  int duree(50);

  double renards_i(0.0);
  double lapins_i(0.0);

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

  // ===== PARTIE 1 =====
  // Saisie des populations initiales
  
  while (renards_i < 2){
	  cout << "Combien de renards au départ (>= 2) ? ";
	  cin >> renards_i;
  }
  
  while (lapins_i < 5){
	  cout << "Combien de lapins au départ  (>= 5) ? ";
	  cin >> lapins_i;			
  }	    
  

  // ===== PARTIE 2 =====
  // Première simulation
  
  cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 
	  << "%" <<  endl;
  double lapins(lapins_i), renards(renards_i);
  for (int i(1); i <= duree; i++){
	  double rens, laps;
	  laps =  lapins * (1.0 + taux_croissance_lapins - taux_attaque
  			  * renards);
	  rens = renards * (1.0 + taux_attaque * lapins
			  * taux_croissance_renards - taux_mortalite);
	  lapins = laps >= 0? laps : 0;
	  renards = rens >= 0? rens : 0;		
	  cout <<"Après " << i << " mois, il y a " 
  		  << lapins	<< " lapins et " 
  		  << renards << " renards" << endl;
  }

  // ===== PARTIE 3 =====
  // Variation du taux d'attaque

  double tad(0), taf(0);
  
  while (true){
	  cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";
	  cin >> tad;
	  if ((tad >= 0.5) and (tad <=6)){
  		  tad /= 100;
  		  break;
	  }
  }

  while(true){
	  cout << "taux d'attaque à la fin  en % (entre " << tad * 100;
	  cout << " et 6) ? ";
	  cin >> taf;
	  if ((taf >= tad * 100) and (taf <= 6)){
		  taf /= 100;
		  break;
	  }
  }
  
  for (; tad <= taf; tad += 0.01){
	  double duree_exp = duree;
	  cout <<  endl << "***** Le taux d'attaque vaut "
		  << tad * 100 << "%" <<endl;
	  lapins = lapins_i;
	  renards = renards_i;
	  bool ren_ext(false), lap_ext(false), lap_disp(false), ren_disp(false),
	       lap_rem(false), ren_rem(false);
	  for (int i = 1; i <= duree; i++){
		  double laps =  lapins * (1.0 + taux_croissance_lapins - tad
				* renards);
			double rens = renards * (1.0 + tad * lapins
						* taux_croissance_renards 
						- taux_mortalite);
			lapins = laps;
			renards = rens;

			if (lapins > 5) {
				if (lap_ext){
					lap_rem = true;
				} 
			} else if (lapins < 2) {
				lapins = 0.0;
				if (!lap_ext){
					lap_ext = true;
				}
				if (!lap_disp) {
					lap_disp = true;
				}
			} else if (!lap_ext){
				lap_ext = true;			
			}

			if (renards > 5) {
				if (ren_ext){
					ren_rem = true;
				} 
			} else if (renards < 2) {
				renards = 0.0;
				if (!ren_ext){
					ren_ext = true;
				}
				if (!ren_disp) {
					ren_disp = true;
				}
			} else if (!ren_ext){
				ren_ext = true;
			}			
					
			if (ren_disp and lap_disp) {
				duree_exp = i;
				break;
			}
	  }

	  cout << "Après " << duree_exp << " mois, il y a " << lapins 
  		  << " lapins et " << renards << " renards" << endl;
	  if (!ren_ext and !ren_disp and !lap_ext and !lap_disp and !lap_rem
	  		  and !ren_rem) {
  		  cout << "Les lapins et les renards ont des populations stables." 
	  		  << endl;
	  } else{
		  if (ren_ext){
			  cout << "Les renards ont été en voie d'extinction" << endl;
		  }
		  if (ren_rem){
			  cout << "mais la population est remontée ! Ouf !" << endl;
		  }
		  if (ren_disp) {
			  cout << "et les renards ont disparu :-(" << endl;
		  }
		  if (lap_ext){
			  cout << "Les lapins ont été en voie d'extinction" << endl;
		  }
		  if (lap_rem){
			  cout << "mais la population est remontée ! Ouf !" << endl;
		  }
		  if (lap_disp) {
			  cout << "et les lapins ont disparu :-(" << endl;
		  }
	  }	
} 
  

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
