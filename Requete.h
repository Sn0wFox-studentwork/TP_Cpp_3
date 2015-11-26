/*************************************************************************
						Requete  -  description
-------------------
début                : 23/11/2015
copyright            : (C) 2015 par Pericas-Moya & Belletier
*************************************************************************/

//---------- Interface de la classe <Requete> (fichier requete.h) ------
#if ! defined ( REQUETE_H )
#define REQUETE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

#include "PageInternet.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Requete>
//
//
//------------------------------------------------------------------------ 

class Requete
{

//----------------------------------------------------------------- PUBLIC
public:

//----------------------------------------------------- Méthodes publiques
	PageInternet GetReferenceur ( ) const;
	PageInternet GetCible ( ) const;
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//


//------------------------------------------------- Surcharge d'opérateurs
	Requete &operator = (const Requete &unRequete);
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool operator< ( const Requete& autreRequete ) const;
	// Base sur Ordre lexicographique (< pour les string) : 1) referenceur 2) cible

	bool operator== ( const Requete& autreRequete ) const;
	// Base sur Ordre lexicographique (< pour les string) : 1) referenceur 2) cible


//-------------------------------------------- Constructeurs - destructeur
	Requete ( const Requete &uneRequete );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Requete ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

	Requete ( PageInternet* referenceur, PageInternet* cible );
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Requete ( );
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
	PageInternet referenceur;
	PageInternet cible;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Requete>

#endif // REQUETE_H
