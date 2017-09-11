#include<iostream>
using namespace std;

int main()
{
	double v1(1.0), v2(2.0), v3(3.0);
	double *choix = NULL;
 
	int chn;
	while (choix == NULL) {
		cout << "Choisissez un nombre: 1, 2 ou 3? " << endl;
		cin >> chn;
		switch (chn){ 
			case 1: 
				choix = &v1;
				break;
			case 2: 
				choix = &v2;
				break;
			case 3:
				choix = &v3;
				break;
			default:
				cout << "Mauvais nombre, réessayez! " << endl;
		}
	}
	cout << "Vous aves choisi : " << *choix << endl;
	return 0;
}
