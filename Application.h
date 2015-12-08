/*************************************************************************
						Application  -  description
-------------------
début                : 23/11/2015
copyright            : (C) 2015 par Pericas-Moya & Belletier
*************************************************************************/

//---------- Interface de la classe <Application> (fichier Application.h) ------
#if ! defined ( APPLICATION_H )
#define APPLICATION_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <cstdint>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

#include "PageInternet.h"
#include "Arc.h"

//------------------------------------------------------------------ Types
typedef uint16_t Uint16;							// Type des flags (= options)
typedef std::vector<Arc> Arcs;					// Type des liens
typedef std::map<PageInternet, Arcs> Graphe;		// Map de [noeud, liens vers noeud] (=[PageInternet, Ensemble des autres Page la referencant])
typedef Graphe::iterator IterateurGraph;			// Iterateur pour map de requete

//------------------------------------------------------------- Constantes

// Les constantes suivantes representent les options avec lesquelles on peut lancer l'application :
const Uint16 FLAG_NO_FLAGS		=	0x0000;								// Sans option
const Uint16 FLAG_DRAW_GRAPH	=	0x0001;								// Dessiner le graphe [-g]
const Uint16 FLAG_NO_IMAGE		=	0x0010;								// Exclure les images
const Uint16 FLAG_NO_SCRIPT		=	0x0100;								// Eclure les scripts js et css
const Uint16 FLAG_E_OPTION		=	FLAG_NO_IMAGE | FLAG_NO_SCRIPT;		// Exclure scripts et images [-e]
const Uint16 FLAG_ONE_HOUR		=	0x1000;								// Pour une heure precise [-t]
const Uint16 FLAG_ALL_FLAGS		=	FLAG_DRAW_GRAPH | FLAG_E_OPTION | FLAG_ONE_HOUR;	// Toutes les options precedentes

//------------------------------------------------------------------------
// Rôle de la classe <Application>
// La classe Application gere le fonctionnement global de l'application Analog.
//
//
//------------------------------------------------------------------------

class Application
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	int Run ( const std::string& nomGraphe = "void.dot", int heure = 0 );
	// Mode d'emploi :	Lance l'application en effectuant uniquement les traitements definis par flags.
	//					Exemple :	Donner en parametre une valeur pour nomGraphe ne fera strictement
	//								rien si le flag FLAG_DRAW_GRAPH n'est pas present.
	//					Si le nom du graphe nomGraphe ne comporte pas de ".dot", celui-ci sera ajoute.
	//					Retourne 0 si tout c'est bien passe.
	//					Retourne -100X si erreur, X fonction de l'erreur :
	//						1 si le fichier d'entree n'a pas pu etre trouve.
	//						2 si impossible d'ouvrir le fichier de sortie.


	void SetFlags ( Uint16 newFlags );
	// Mode d'emploi :	Remplace les options de l'application par ceux definis par newFlags.
	// Contrat :		L'utilisateur doit uniquement utiliser les flags existants,
	//					qui sont definis dans Application.h.

//------------------------------------------------- Surcharge d'opérateurs
	Application& operator = ( const Application &uneApplication );
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	Application ( const Application &uneApplication );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Application ( std::string fichierEntree, Uint16 flags = FLAG_NO_FLAGS );
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Application ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	int ecrireGraph ( const std::string& filename );
	// Mode d'emploi :	Retourne 0 si le graph a pu etre ecrit,
	//					-1002 sinon.
	//
	// Contrat :
	//

	void afficherResultats ( );
	// Mode d'emploi :	Affiche les 10 PageInternets les plus consultees.
	//
	// Contrat :
	//

	void remplirGraph ( const PageInternet& pageArc, const PageInternet& pageRequetrice );
	// Mode d'emploi :
	//
	// Contrat :
	//

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	std::string fichierEntree;
	Graphe graphe;
	Uint16 flags;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Application>

#endif // APPLICATION_H


