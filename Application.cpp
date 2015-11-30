/*************************************************************************
                           Application  -  description
                             -------------------
    début                : 23/11/2015
    copyright            : (C) 2015 par Pericas-Moya & Belletier
*************************************************************************/

//---------- Réalisation de la classe <Application> (fichier Application.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "Application.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Application::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


int Application::Run ( int heure )
// Algorithme :
{
	// Declarations des variables de traitement
	ifstream fichier(fichierEntree, ios::in);
	string lecture;

	// Verification que le fichier ai bien ete ouvert
	if ( !fichier )
	{
		// Si le fichier n'existe pas (mauvais chemin d'acces), fin de la methode
		cerr << "Fichier d'entree " + fichierEntree + " introuvable." << endl;
		return -1001;
	}
	
	// Lecture du fichier et remplissage des structures
	while ( getline ( fichier, lecture ) )		// Tant qu'il y a des lignes a lire
	{
		remplirNoeuds( lecture, heure );
		if ( flags & DRAW_GRAPH )
		{
			remplirRequetes( lecture, heure );
		}
	}

	// Dessin du graphe si l'option a ete specifiee
	if ( flags & DRAW_GRAPH )
	{
		return ecrireGraph( );		// On renvoie le code retour de ecrireGraph
	}
	else
	// Sinon, affichage des dix pages les plus consultees
	{
		afficherResultats( );
	}

	return 0;
}

void Application::SetFlags ( Uint16 newFlags )
// Algorithme :
{
	flags = newFlags;

}	//----- Fin de SetFlags

//------------------------------------------------- Surcharge d'opérateurs
Application& Application::operator = ( const Application & uneApplication )
// Algorithme :	Si on n'est pas en train de faire uneApplication = uneApplication,
//				on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de uneApplication.
//				On utilisera la surcharge de = pour les maps, strings et Uint16.
{
	if ( this != &uneApplication )
	{
		fichierEntree = uneApplication.fichierEntree;
		dicoNoeuds = uneApplication.dicoNoeuds;
		dicoRequetes = uneApplication.dicoRequetes;
		flags = uneApplication.flags;
	}
	return *this;
}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Application::Application ( const Application & uneApplication ) :
	fichierEntree( uneApplication.fichierEntree ),
	dicoNoeuds( uneApplication.dicoNoeuds ), dicoRequetes( uneApplication.dicoRequetes ),
	flags( uneApplication.flags )
// Algorithme :	Utilisation des constructeurs de copie de string, map et Uint16 (uint16_t).
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Application>" << endl;
#endif
	// Rien de plus a faire ici

} //----- Fin de Application (constructeur de copie)


Application::Application ( string fichierIn, Uint16 f ) :
	fichierEntree( fichierIn ), dicoNoeuds( ), dicoRequetes( ), flags( f )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Application>" << endl;
#endif

} //----- Fin de Application


Application::~Application ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Application>" << endl;
#endif

	// Désallocation de la map de requetes
	for ( IterateurRequete it = dicoRequetes.begin( ); it !=dicoRequetes.begin( ); it++ )
	{
		delete it->first;
	}

}	//----- Fin de ~Application

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
int Application::ecrireGraph ( )
// Algorithme :
{
	// TODO :	implanter l'ecriture du graph
	return 0;
	return -1002;		// En cas d'erreur lors de l'ecriture
}	//----- Fin de ecrireGraph

void Application::afficherResultats ( )
// Algorithme :
{
	// TODO : implanter le code de recherche et d'affichage des pages les plus consultees

}	//----- Fin de remplirRequetes

void Application::remplirRequetes ( std::string& ligne, int heure )
// Algorithme :
{
	if ( flags & ONE_HOUR )
	{
		// TODO : verifier si on prend ou si on rejette la ligne
	}

	if ( flags & E_OPTION )
	{
		// TODO : verifier si on prend ou si on rejette la ligne
	}

	// TODO : implanter le code d'insertion dans le dico de requetes

}	//----- Fin de remplirRequetes

void Application::remplirNoeuds ( std::string& ligne, int heure )
// Algorithme :
{
	if ( flags & ONE_HOUR )
	{
		// TODO : verifier si on prend ou si on rejette la ligne
	}

	if ( ( flags & E_OPTION ) == E_OPTION )
	{
		// TODO : verifier si on prend ou si on rejette la ligne
	}

	// TODO : implanter le code d'insertion dans le dico de noeuds

}	//----- Fin de remplirNoeuds

//------------------------------------------------------- Méthodes privées
