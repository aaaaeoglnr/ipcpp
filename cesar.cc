#include<iostream>
#include<string>
using namespace std;

char code(char);
char decale(char, char, int);
string code(string, int);
string decode(string, int);

int main()
{
	return 0;
}

char code(char c, int decalage)
{
	if((c >= 'a') and (c <= 'z')) {
		return decale(c, 'a', decalage);
	} else if ((c >= 'A') and (c <= 'Z')) {
		return decale(c, 'A', decalage);
	}
	return c;
}

char decale(char c, char debut, int decalage)
{
	while (decalage < 0) {decalage += 26;}
	return debut + (((c - debut) + decalage) % 26);
}

string code(string s, int decalage)
{
	string sc = "";
	for (int i(0); i < s.size(); i++){
		sc += code(s[i], decalage);
	}
	return sc;

}

string decode(string s, int decalage)
{
	return code(s, -decalage);
}
