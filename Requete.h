/*************************************************************************
						Requete  -  description
-------------------
d�but                : 23/11/2015
copyright            : (C) 2015 par Pericas-Moya & Belletier
*************************************************************************/

//---------- Interface de la classe <Requete> (fichier requete.h) ------
#if ! defined ( REQUETE_H )
#define REQUETE_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>

#include "PageInternet.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Requete>
//
// 
//------------------------------------------------------------------------ 

class Requete
{

//----------------------------------------------------------------- PUBLIC
public:

//----------------------------------------------------- M�thodes publiques
	
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

	void IncrementeNombreAcces ( ) { nombreAcces++ ; }

//------------------------------------------------- Surcharge d'op�rateurs
	Requete &operator = ( const Requete& uneRequete );
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool operator == ( const Requete& uneRequete ) const;

//-------------------------------------------- Constructeurs - destructeur
	Requete ( const Requete &uneRequete );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Requete ( PageInternet * const requeteur = nullptr );
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
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s
	PageInternet* requeteur;
	int nombreAcces;
	// TODO : rajouter d'autres attributs

private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Requete>

#endif // REQUETE_H
