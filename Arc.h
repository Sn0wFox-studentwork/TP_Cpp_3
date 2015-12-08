/*************************************************************************
						Arc  -  description
-------------------
début                : 23/11/2015
copyright            : (C) 2015 par Pericas-Moya & Belletier
*************************************************************************/

//---------- Interface de la classe <Arc> (fichier requete.h) ------
#if ! defined ( REQUETE_H )
#define REQUETE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

#include "PageInternet.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Arc>
//
// 
//------------------------------------------------------------------------ 

class Arc
{

//----------------------------------------------------------------- PUBLIC
public:

//----------------------------------------------------- Méthodes publiques
	
	int GetNombreAcces ( ) const { return nombreAcces; }
	// Mode d'emploi :
	//
	// Contrat :
	//

	PageInternet* GetPageInternet ( ) const { return requeteur; }
	// Mode d'emploi :
	//
	// Contrat :
	//

	void IncrementeNombreAcces ( ) { ++nombreAcces ; }

//------------------------------------------------- Surcharge d'opérateurs
	Arc &operator = ( const Arc& uneArc );
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool operator == ( const Arc& uneArc ) const;

//-------------------------------------------- Constructeurs - destructeur
	Arc ( const Arc &uneArc );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Arc ( PageInternet * const requeteur = nullptr );
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Arc ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	PageInternet* requeteur;
	int nombreAcces;
	// TODO : rajouter d'autres attributs

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Arc>

#endif // REQUETE_H
