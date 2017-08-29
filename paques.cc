#include<iostream>
using namespace std;

int demander_annee()
{
	int annee(0);
	while(true){
		cout << "Entrez une annee (1583-4000): ";
		cin >> annee;
		if ((annee >= 1583) and (annee <= 4000)){
			return annee;
		}
	}
}

void affiche_date(int annee, int journees){
	cout << "Date de Paques en "<<annee<<": ";
	if (journees <= 31){
		cout << journees << " mars";
	} else {
		cout << journees - 31 << " avril";
	}
	cout << endl;
}

int date_Paques(int annee)
{
	int siecle(annee/100);
	int p = (13 + siecle * 8) / 25;
	int q = siecle / 4;
	int m = (15 - p + siecle - q) % 30;
	int n = (4 + siecle - q) % 7;
	int d = (m + 19 * (annee % 19)) % 30;
       	int e = (2 * (annee % 4) + 4 * (annee % 7) + 6 *d + n) % 7;
	int journees = e + d + 22;
	if ((e == 6) and ((d == 29) or ((d == 28) and (11 * (m+1) % 30 <19)))){
		journees -= 7;
	}
	return journees;
}


int main()
{
	int annee = demander_annee();
	affiche_date(annee, date_Paques(annee));
	return 0;
}
