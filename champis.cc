  #include<iostream>
  using namespace std;
  
  int main()
  {
	  int anneau, foret, convexe, lamelles;
  cout << "Pensez Ã  un champignon : amanite tue-mouches, pied bleu, girolle," << endl
       << "cÃ¨pe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl << endl;
  cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
  cin >> anneau;
  if (anneau){
	  cout << "Est-ce que votre champignon vit en forÃªt (1 : oui, 0 : non) ? ";
	  cin >> foret;
	  if (foret){
		  cout << "==> Le champignon auquel vous pensez est ";
		  cout << "l'amanite tue-mouches";
	  } else {
		  cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
		  cin >> convexe;
		  cout << "==> Le champignon auquel vous pensez est ";
		  if (convexe) {cout << "l'agaric jaunissant";} 
		  else {cout << "le coprin chevelu";}
	  }
  } else {
	  cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
	  cin >> convexe;
	  if (convexe){
		  cout << "==> Le champignon auquel vous pensez est ";
		  cout << "le pied bleu";
	  } else {
		cout << "Est-ce que votre champignon a des lamelles (1 : oui, 0 : non) ? ";
		cin >> lamelles;
		cout << "==> Le champignon auquel vous pensez est ";
		if (lamelles) {
			cout << "la girolle";
		} else {
		 cout << "le cÃ¨pe de Bordeaux";
		}
	  }
		  
  }
}
  
  
  
  

  

  
  
  
  
  
  
