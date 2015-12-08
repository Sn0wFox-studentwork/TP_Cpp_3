/*************************************************************************
                           Arc  -  description
                             -------------------
    d�but                : 23/11/2015
    copyright            : (C) 2015 par Pericas-Moya & Belletier
*************************************************************************/

//---------- R�alisation de la classe <Arc> (fichier Arc.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Arc.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type Arc::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
Arc & Arc::operator = ( const Arc & uneArc )
// Algorithme :	Si on n'est pas en train de faire uneArc = uneArc,
//				on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de uneArc.
//				On utilisera la surcharge de = pour les PageInternets.
{
	if ( this != &uneArc )
	{
		requeteur = uneArc.requeteur;
		nombreAcces = uneArc.nombreAcces;
	}

	return *this;

}	//----- Fin de operator =


bool Arc::operator== ( const Arc& uneArc ) const
// Algorithme :
{
	return *requeteur == *uneArc.requeteur;
}	//----- Fin de operator==

//-------------------------------------------- Constructeurs - destructeur
Arc::Arc ( const Arc & uneArc ) :
	requeteur( uneArc.requeteur ), nombreAcces( uneArc.nombreAcces )
// Algorithme :	Construction a partir du constructeur par copie de PageInternet.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Arc>" << endl;
#endif

}	//----- Fin de Arc ( constructeur de copie )


Arc::Arc ( PageInternet * const pageRequetrice ) : requeteur( nullptr ), nombreAcces ( 1 )
// Algorithme :	Construction par defaut grace au constructeur par defaut de PageInternet.
{
#ifdef MAP
    cout << "Appel au constructeur de <Arc>" << endl;
#endif

	requeteur = pageRequetrice;

}	//----- Fin de Arc


Arc::~Arc ( )
// Algorithme :
{
#ifdef MAP
    cout << "Appel au destructeur de <Arc>" << endl;
#endif

} //----- Fin de ~Arc


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
