#include <iostream>
#include <string>
#include <cstdlib>
#include <cstddef>
#include "Application.h"

using namespace std;

void Tests( );
void TestFlags( );
void TestFind( );

int main ( unsigned int argc, char** argv )
// Algorithme :	On commence par recuperer les options et le fichier d'entree.
//				S'il n'y a pas de parametre d'entree (i.e. argc = 1), fin de l'application avec le code -1.
//				On cree ensuite une instance de Application avec le fichier d'entree associe,
//				ou on termine l'application avec le code -2 si le nom du fichier d'entree n'est pas valide (vide).
//				On lance l'application via Run( ) avec les options voulues, qui produit le resultat.
{
	// Declaration des variables de stockage et de manipulation
	Uint16 flags = NO_FLAGS;
	string lecture;
	string heure = "0";
	string nomFichierEntree;
	string nomGraph = "";

	// Tests unitaires
	Tests( );
	TestFlags( );
	TestFind( );
	
	// Recuperation des parametres
	if ( argc < 2 )
	{
		// Si pas de parametres, fin de l'application
		cerr << "Pas assez de parametres" << endl;
		return -1;
	}
	for ( unsigned int i = 1; i < argc; i++ )		// On commence a 1 car argv[0] est le chemin vers notre executable
	{
		lecture = argv[i];
		// Recuperation des options
		if ( lecture[0] == '-' && lecture.size() != 1 )		// On utilise la surcharge de [] pour string
		{
			switch ( lecture[1] )
			{
			case 'g':					// Option [-g]
				flags |= DRAW_GRAPH;
				if ( i + 1 < lecture.size( ) )
				{
					nomGraph = argv[i + 1];
				}
				i++;		// On saute le prochain argument d'entree, puisqu'on vient de le lire
				break;
			case 'e':					// Option [-e]
				flags |= E_OPTION;
				break;
			case 't':					// Option [-t]
				flags |= ONE_HOUR;
				if ( i + 1 < lecture.size( ) )
				{
					heure = argv[i + 1];
				}
				i++;		// On saute le prochain argument d'entree, puisqu'on vient de le lire
				break;
			default:					// Mauvaise option
				break;
			}
		}	//----- Fin de if ( option )
		else
		// Recuperation du fichier d'entree
		{
			nomFichierEntree = argv[i];
		}
	}

	// Creation de l'instance d'Application
	if ( nomFichierEntree.empty() )
	{
		// Si pas de fichier d'entree, fin de l'application
		cerr << "Pas de fichier d'entree" << endl;
		return -2;
	}
	Application app( nomFichierEntree, flags );

	// Lancement du traitement puis fin du programme : on retourne la valeur retournee par Run
	return app.Run( strtol( heure.c_str( ), nullptr, 0 ), nomGraph );

}

void Tests()
{
	// Si la clef n'existe pas, la valeur prend une valeur nulle (fonction du type de la clef)
	Graph ryan;
	PageInternet p1("hi");
	PageInternet p2("hi2");
	ryan[p1];
	ryan[p2];

	for ( IterateurGraph it = ryan.begin( ); it != ryan.end( ); it++ )
	{
		cout << it->first.GetOutputComplet( ) << endl;
	}
}

void TestFlags()
{
	Uint16 flags = ALL_FLAGS;

	// Flags unitaires : la comparaison est inutile
	if ( flags & ONE_HOUR )
	{
		cout << "One_Hour !" << endl;
	}
	if ( flags & DRAW_GRAPH )
	{
		cout << "Draw_Graph !" << endl;
	}
	// Flags composites : la comparaison est obligatoire (parenthese pour enlever un warning du compilo)
	if ( ( flags & E_OPTION ) == E_OPTION )
	{
		cout << "E_Option !" << endl;
	}

	flags = NO_IMAGE;
	cout << "Flags : " << (int)flags << " NO_IMAGE : " << (int)NO_IMAGE << " NO_SCRIPT : " << (int)NO_SCRIPT;
	cout << " E_OPTION : " << (int)E_OPTION << endl;
	if ( flags & NO_IMAGE )
	{
		cout << "No_Image !" << endl;
	}
	if ( !( flags & NO_SCRIPT ) )
	{
		cout << "Pas No_Script !" << endl;
	}
	// Utilisation de flags composites : utiliser l'operateur == apres extraction
	if ( ( flags & E_OPTION ) == E_OPTION )
	{
		cout << "E_Option !" << endl;
	}

}

void TestFind()
{
	string s = " lh 7 trolololo 7 youpi";
	cout << s.find("7", 1, 1) << endl;
	string lecture = "... - - [...] \"GET /temps/trololo/page.html HTTP/1.1\" 200 12325";
	
	size_t posTampon = lecture.find("GET");
	cout << posTampon;
	// Si il ne s'agit pas d'une requete de type GET, on saute la ligne
	if ( posTampon == string::npos )
	{
		cout << "rate !";
		return;
	}
	string tampon = lecture.substr(posTampon + string("GET ").length(),
		lecture.substr(posTampon + string("GET ").length()).find(" "));
	cout << tampon << "-" << endl;

}