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
#include "GrapheRequetes.h"

//------------------------------------------------------------------ Types
typedef uint16_t Uint16;	// Type des flags (= options)

//------------------------------------------------------------- Constantes
const std::string STR_REQUETEUR_EXCLU = "Autre Type Requeteur";		// Signal un requeteur de type indesirable
const std::string STR_SERVER = "http://intranet-if.insa-lyon.fr";

// Les constantes suivantes representent les options avec lesquelles on peut lancer l'application :
const Uint16 FLAG_NO_FLAGS			=	0x0000;								// Sans option
const Uint16 FLAG_DRAW_GRAPH		=	0x0001;								// Dessiner le graphe [-g]
const Uint16 FLAG_NO_IMAGE			=	0x0010;								// Exclure les images
const Uint16 FLAG_NO_SCRIPT			=	0x0100;								// Eclure les scripts js et css
const Uint16 FLAG_EXCLUDE_OPTION	=	FLAG_NO_IMAGE | FLAG_NO_SCRIPT;		// Exclure scripts et images [-e]
const Uint16 FLAG_ONE_HOUR			=	0x1000;								// Pour une heure precise [-t]
const Uint16 FLAG_ALL_FLAGS			=	FLAG_DRAW_GRAPH | FLAG_EXCLUDE_OPTION | FLAG_ONE_HOUR;	// Toutes les options precedentes

//------------------------------------------------------------------------
// Rôle de la classe <Application>
// La classe Application gere le fonctionnement global de l'application Analog.
// C'est elle qui va récupérer le fichier de log et l'analyser pour en synthétiser le contenu.
// Suivant les options (= flags) avec lesquels on a instancié Application, elle effectuera différents traitements.
// Ces traitements ne pourront être effectués que sur un seul et unique fichier.
// Pour analyser d'autres fichiers de journalisations, il faudra créer plusieurs instances de Application.
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
	// Mode d'emploi :	Réaffecte l'instance courante pour la rendre en tout point similaire à uneApplication.

//-------------------------------------------- Constructeurs - destructeur
	Application ( const Application &uneApplication );
	// Mode d'emploi ( constructeur de copie ) :	Consruit une nouvelle instance d'Application
	//												a partir d'une Application existante uneApplication.
	//												L'objet instancie sera en tout point similaire a uneApplication.

	Application ( std::string fichierEntree, Uint16 flags = FLAG_NO_FLAGS );
	// Mode d'emploi :	Construit une nouvelle instance d'Application.
	//					Le paramètre fichierEntree est le nom du fichier de logs qui sera potentiellement analysé
	//					(si appel à Run()).
	//					Le paramètre flags représente les options avec lesquelles les analyses pourront être faites.
	//					Il n'existe pas de constructeur par défaut.
	// Contrat :		L'utilisateur s'engage a n'utiliser que les flags definis plus hauts.

	virtual ~Application ( );
	// Mode d'emploi :	Detruit l'instance et libere la memoire. Appele automatiquement.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

	void afficherResultats ( unsigned int nbResultats = 10 ) const;
	// Mode d'emploi :	Affiche les nbResultats PageInternets les plus consultees,
	//					d'apres le fichier de logs fichierEntree.
	//					Ne gere aucun flag.
	// Contrat :		Ces nbResultats resultats devront etre present dans la structure graphe pour etre affiches.
	//					Tout les autres flags devront avoir ete traites avant.

	void remplirGraph ( const PageInternet& pageArc, const PageInternet& pageRequetrice );
	// Mode d'emploi :	Rempli la structure graphe a partir de pageArc et pageRequetrice.
	//					Ne gere aucun flag.
	// Contrat :		Tout les autres flags devront avoir ete traites avant
	//					(sinon les requetes indesirables seront inserees).

protected:
//----------------------------------------------------- Attributs protégés
	std::string fichierEntree;	// Nom du fichier de logs
	GrapheRequetes graphe;		// Structure permettant de stocker les requetes
	Uint16 flags;				// Options de parsage et d'execution

};

#endif // APPLICATION_H


