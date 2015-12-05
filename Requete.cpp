/*************************************************************************
                           Requete  -  description
                             -------------------
    début                : 23/11/2015
    copyright            : (C) 2015 par Pericas-Moya & Belletier
*************************************************************************/

//---------- Réalisation de la classe <Requete> (fichier Requete.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Requete.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Requete::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Requete & Requete::operator = ( const Requete & uneRequete )
// Algorithme :	Si on n'est pas en train de faire uneRequete = uneRequete,
//				on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de uneRequete.
//				On utilisera la surcharge de = pour les PageInternets.
{
	if ( this != &uneRequete )
	{
		requeteur = uneRequete.requeteur;
		nombreAcces = uneRequete.nombreAcces;
	}

	return *this;

}	//----- Fin de operator =


bool Requete::operator== ( const Requete& uneRequete ) const
// Algorithme :
{
	return *requeteur == *uneRequete.requeteur;
}	//----- Fin de operator==

//-------------------------------------------- Constructeurs - destructeur
Requete::Requete ( const Requete & uneRequete ) :
	requeteur( uneRequete.requeteur ), nombreAcces( uneRequete.nombreAcces )
// Algorithme :	Construction a partir du constructeur par copie de PageInternet.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Requete>" << endl;
#endif

}	//----- Fin de Requete ( constructeur de copie )


Requete::Requete ( PageInternet * const pageRequetrice ) : requeteur( nullptr )
// Algorithme :	Construction par defaut grace au constructeur par defaut de PageInternet.
{
#ifdef MAP
    cout << "Appel au constructeur de <Requete>" << endl;
#endif

	requeteur = pageRequetrice;

}	//----- Fin de Requete


Requete::~Requete ( )
// Algorithme :
{
#ifdef MAP
    cout << "Appel au destructeur de <Requete>" << endl;
#endif

} //----- Fin de ~Requete


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
