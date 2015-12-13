/*************************************************************************
		main  -  contient le point d'entrée de l'application
-------------------
début                : 23/11/2015
copyright            : (C) 2015 par Pericas-Moya & Belletier
*************************************************************************/

//---------- Réalisation du main (fichier main.cpp) ----------------------
//#define MAP

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstddef>

//------------------------------------------------------ Include personnel
#include "Application.h"
#ifdef MAP
#include "TestsUnitaires.h"
#endif

int main ( int argc, char** argv )
// Algorithme :	On commence par recuperer les options et le fichier d'entree.
//				S'il n'y a pas de parametre d'entree (i.e. argc = 1), fin de l'application avec le code -1.
//				On cree ensuite une instance de Application avec le fichier d'entree associe,
//				ou on termine l'application avec le code -2 si le nom du fichier d'entree n'est pas valide (vide).
//				On lance l'application via Run( ) avec les options voulues, qui produit le resultat.
//				Retourne le code renvoye par Run( ).
{
	// Declaration des variables de stockage et de manipulation
	Uint16 flags = FLAG_NO_FLAGS;
	string lecture;
	string heure = "0";
	string nomFichierEntree;
	string nomGraph = "";
	int verifHeure = 0;

#ifdef MAP
	// Inserer les tests unitaires ici
	TestPrintResultats( );
#endif

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
				flags |= FLAG_EXCLUDE_OPTION;
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
				cerr << "Option inconnue" << endl;
				return -4;
			}
		}	//----- Fin de if ( option )
		else
		// Recuperation du fichier d'entree
		{
			// S'il subsiste des parametres
			if ( i != argc-1 )
			{
				cerr << "Trop de parametres" << endl;
				return -5;
			}
			nomFichierEntree = argv[i];
		}
	}

	// Verification de la coherence de l'heure
	verifHeure = atoi( heure.c_str( ) );
	if ( verifHeure > 23 || verifHeure < 0 )
	{
		cerr << "Heure specifiee invalide" << endl;
		return -3;
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
	return app.Run( nomGraph, verifHeure );

}	//----- Fin de main
