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
#include <string>
#include <fstream>
#include <vector>

#include "PageInternet.h"
#include "Requete.h"

//------------------------------------------------------------------ Types
typedef uint16_t Uint16;							// Type des flags (= options)
typedef std::vector<Requete> Arcs;					// Type des liens
typedef std::map<PageInternet, Arcs> Graph;			// Map de [noeud, liens vers noeud] (=[PageInternet, Ensemble des autres Page la referencant])
typedef Graph::iterator IterateurGraph;				// Iterateur pour map de requete

//------------------------------------------------------------- Constantes

// Les constantes suivantes representent les options avec lesquelles on peut lancer l'application :
const Uint16 NO_FLAGS	=		0x0000;								// Sans option
const Uint16 DRAW_GRAPH	=		0x0001;								// Dessiner le graphe [-g]
const Uint16 NO_IMAGE	=		0x0010;								// Exclure les images
const Uint16 NO_SCRIPT	=		0x0100;								// Eclure les scripts js et css
const Uint16 E_OPTION	=		NO_IMAGE | NO_SCRIPT;				// Exclure scripts et images [-e]
const Uint16 ONE_HOUR	=		0x1000;								// Pour une heure precise [-t]
const Uint16 ALL_FLAGS	=		DRAW_GRAPH | E_OPTION | ONE_HOUR;	// Toutes les options precedentes

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
	int Run ( int heure = 0, const std::string& nomGraph = "void.dot" );
	// Mode d'emploi :	Lance l'application en effectuant les traitements definis par flags.
	//					Retourne 0 si tout c'est bien passe.
	//					Retourne -100X si erreur, X fonction de l'erreur.
	//					TODO : preciser les autres codes de retour.
	// Contrat :
	//

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

	Application ( std::string fichierEntree, Uint16 flags = NO_FLAGS );
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
	int ecrireGraph ( std::string filename );
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

	void remplirGraph ( const std::string& requete, const std::string& requeteur );
	// Mode d'emploi :
	//
	// Contrat :
	//

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	std::string fichierEntree;
	Graph graph;
	Uint16 flags;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Application>

#endif // APPLICATION_H


