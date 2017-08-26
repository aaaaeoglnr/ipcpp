#include <iostream>
using namespace std;

int main()
{
  int debut(0);
  do {
    cout << "de (>= 1) ? ";
    cin >> debut;
  } while (debut < 1);

  int fin(0);
  do {
    cout << "a (>= " << debut << ") ? ";
    cin >> fin;
  } while (fin < debut);

  /*******************************************
   * Completez le programme a partir d'ici.
   *******************************************/
	for (int i(debut); i <= fin; i++){
		int k = 0;
		int nb = i;
		while (nb){
			if (nb % 3 == 0){
				nb += 4;
			} else if (nb % 4 == 0){
					nb /= 2;
			} else {nb -= 1;}
			k++;
		}
		cout <<i << "->"<<k<<endl;
	} 

  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}
