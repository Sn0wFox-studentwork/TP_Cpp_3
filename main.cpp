#include <iostream>
#include <string>
#include <cstdlib>
#include <cstddef>

#include "Application.h"

// TODO : remove when release :
//#include "TestsUnitaires.h"

using namespace std;

int main ( int argc, char** argv )
// Algorithme :	On commence par recuperer les options et le fichier d'entree.
//				S'il n'y a pas de parametre d'entree (i.e. argc = 1), fin de l'application avec le code -1.
//				On cree ensuite une instance de Application avec le fichier d'entree associe,
//				ou on termine l'application avec le code -2 si le nom du fichier d'entree n'est pas valide (vide).
//				On lance l'application via Run( ) avec les options voulues, qui produit le resultat.
{
	// Declaration des variables de stockage et de manipulation
	Uint16 flags = FLAG_NO_FLAGS;
	string lecture;
	string heure = "0";
	string nomFichierEntree;
	string nomGraph = "";
	
	// Recuperation des parametres
	if ( argc < 2 )
	{
		// Si pas de parametres, fin de l'application
		cerr << "Pas assez de parametres" << endl;
		return -1;
	}
	for ( int i = 1; i < argc; i++ )		// On commence a 1 car argv[0] est le chemin vers notre executable
	{
		lecture = argv[i];
		// Recuperation des options
		if ( lecture[0] == '-' && lecture.size() != 1 )		// On utilise la surcharge de [] pour string
		{
			switch ( lecture[1] )
			{
			case 'g':					// Option [-g]
				flags |= FLAG_DRAW_GRAPH;
				if ( i + 1 < argc )
				{
					nomGraph = argv[i + 1];
				}
				i++;		// On saute le prochain argument d'entree, puisqu'on vient de le lire
				break;
			case 'e':					// Option [-e]
				flags |= FLAG_E_OPTION;
				break;
			case 't':					// Option [-t]
				flags |= FLAG_ONE_HOUR;
				if ( i + 1 < argc )
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
	if ( nomFichierEntree.empty( ) )
	{
		// Si pas de fichier d'entree, fin de l'application
		cerr << "Pas de fichier d'entree" << endl;
		return -2;
	}
	Application app( nomFichierEntree, flags );

	// Lancement du traitement puis fin du programme : on retourne la valeur retournee par Run
	return app.Run( nomGraph, strtol( heure.c_str( ), nullptr, 0 ) );

}
