#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
                                                    * all compilers seems to support it :-( */

char tirer_couleur()
{
  static const char* const couleurs = ".RGBCYM";
  static const int nb = strlen(couleurs) - 1;

  return couleurs[distribution(generateur,
                               std::uniform_int_distribution<int>::param_type {0, nb})];
}

// ======================================================================
char poser_question()
{
  char lu(' ');
  cout << "Entrez une couleur : ";
  cin >> lu;
  return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
  char lu(poser_question());
  while (not couleur_valide(lu)) {
    cout << "'" << lu << "' n'est pas une couleur valide." << endl;
    cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
    lu = poser_question();
  }
  return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
  cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
  while (nb-- > 0) {
    cout << c;
  }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
                   char r1, char r2, char r3, char r4)
{
  afficher_couleurs(c1, c2, c3, c4);
  cout << " : ";
  afficher_reponses(c1, c2, c3, c4,
                    r1, r2, r3, r4);
  cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
  cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
  cout << "Perdu :-(" << endl;
  cout << "La bonne combinaison était : ";
  afficher_couleurs(c1, c2, c3, c4);
  cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

// ======================================================================
bool couleur_valide(char c){
	return ((c == '.') or (c == 'R') or (c == 'G') or (c == 'B') or (c == 'C') or (c == 'M') or (c == 'Y'));
}

// ======================================================================
bool verifier(char couleur, char& reponse, int& score
             )
{
	if (couleur == reponse) {
		score++;
		reponse = 'x';
		return true;
	}
	return false;
}

// ======================================================================
void apparier(char reponse, char& c1, char& c2, char& c3, int& numero
             )
{
	if (reponse == c1) {
		c1 = 'x';
		numero++;
	} else if (reponse == c2) {
		c2 = 'x';
		numero++;
	} else if (reponse == c3) {
		c3 = 'x';
		numero++;
	}
}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4)
{
	int correctes(0);
	verifier(r1, c1, correctes);
	verifier(r2, c2, correctes);
	verifier(r3, c3, correctes);
	verifier(r4, c4, correctes);
	int mauvais_placees(0);
	char cr1, cr2, cr3, cr4;
	cr1 = c1 == 'x' ? 'x' : r1;
	cr2 = c2 == 'x' ? 'x' : r2;
	cr3 = c3 == 'x' ? 'x' : r3;
	cr4 = c4 == 'x' ? 'x' : r4;
	if (c1 != 'x') {apparier(c1, cr2, cr3, cr4, mauvais_placees);}
	if (c2 != 'x') {apparier(c2, cr1, cr3, cr4, mauvais_placees);}
	if (c3 != 'x') {apparier(c3, cr1, cr2, cr4, mauvais_placees);}
	if (c4 != 'x') {apparier(c4, cr1, cr2, cr3, mauvais_placees);}
	afficher(correctes, '#');
	afficher(mauvais_placees, '+');
	afficher(4 - correctes - mauvais_placees, '-');

}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
           char r1, char r2, char r3, char r4)
{
	return ((c1 == r1) and (c2 == r2) and (c3 == r3) and (c4 == r4));
}

// ======================================================================
void jouer(int max = 8
	  )
{
	char r1(tirer_couleur());
	char r2(tirer_couleur());
	char r3(tirer_couleur());
	char r4(tirer_couleur());

	int coups(1);
	while(true){
		char c1, c2, c3, c4;
		c1 = lire_couleur();
		c2 = lire_couleur();
		c3 = lire_couleur();
		c4 = lire_couleur();
		afficher_coup(c1, c2, c3, c4, r1, r2, r3, r4);
		if (gagne(c1, c2, c3, c4, r1, r2, r3, r4)) {
			message_gagne(coups);
			return;
		} 
		if (coups == max) { break;}
		coups++;
	}
	message_perdu(r1, r2, r3, r4);
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  jouer();
  return 0;
}
