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

//------------------------------------------------------------------ Types
struct EtatNoeud;										// Declaration anticipee ; realisation plus loin
typedef uint16_t Uint16;								// Type des flags (options)
typedef std::map<std::string, EtatNoeud> DicoNoeuds;	// Map de noeuds (adresses de PageInternet)
typedef std::map<std::string, int> DicoRequetes;		// Map de requetes
typedef DicoNoeuds::iterator IterateurNoeud;			// Iterateur pour map de noeuds
typedef DicoRequetes::iterator IterateurRequete;		// Iterateur pour map de requete

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
//
//
//------------------------------------------------------------------------ 

class Application
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	int Run ( int heure = 0 );
	// Mode d'emploi :	Lance l'application en effectuant les traitements definis par flags.
	//					Retourne 0 si tout c'est bien passe.
	//					Retourne -100X si erreur, X fonction de l'erreur.
	//					TODO : preciser les autres codes de retour.
	// Contrat :
	//

	void SetFlags ( Uint16 newFlags );
	// Mode d'emploi :
	//
	// Contrat :
	//


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
	int ecrireGraph ( );
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

	void remplirRequetes ( std::string& ligne, int heure );
	// Mode d'emploi :
	//
	// Contrat :
	//

	void remplirNoeuds ( std::string& ligne, int heure );
	// Mode d'emploi :
	//
	// Contrat :
	//

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	std::string fichierEntree;
	DicoNoeuds dicoNoeuds;
	DicoRequetes dicoRequetes;
	Uint16 flags;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Application>
// TODO : est-ce bien la place de EtatNoeud dans ce squelette ?
struct EtatNoeud
// Rôle de la struct <EtatNoeud> :
//
{
	// Constructeurs / Destructeur
	EtatNoeud() : Occurences( 0 ), EstIsole( true ) { }
	EtatNoeud( const EtatNoeud& unEtat ) : Occurences(unEtat.Occurences),
		EstIsole(unEtat.EstIsole) { }
	~EtatNoeud() { }

	// Surcharge d'operateurs
	EtatNoeud& operator++ ( )			// ++ en prefix
	{
		++Occurences;
		return *this;
	}
	EtatNoeud operator++(int)			// ++ en postfix
	{
		EtatNoeud res(*this);
		++(*this);
		return res;
	}

	// Attributs
	int Occurences;
	bool EstIsole;
};

#endif // APPLICATION_H


