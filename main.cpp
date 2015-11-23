#include <iostream>
#include <string>
#include "Application.h"
using namespace std;



int main(int argc, char** argv)
{
	// Si la clef n'existe pas, la valeur prend une valeur nulle (fonction du type de la clef)
	DicoNoeuds ryan;
	ryan["hi"]++;
	ryan["hi2"]++;
	ryan["hi"]++;	// Recherche dans une arbre rouge et noir... log(n)
	
	EtatNoeud e;

	cout << e++.Occurences << endl;
	cout << ++e.Occurences << endl;

	for (DicoNoeuds::iterator it = ryan.begin(); it != ryan.end(); it++)
	{
		cout << it->first << ends << it->second.Occurences << endl;
	}
		

	return 0;

}