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
	// type M�thode ( liste de param�tres );
	// Mode d'emploi :
	//
	// Contrat :
	//


//------------------------------------------------- Surcharge d'op�rateurs
	Requete &operator = ( const Requete &unRequete );
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
	Requete ( const Requete &uneRequete );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Requete ( PageInternet * const requeteur );
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
	PageInternet* Requeteur;
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
