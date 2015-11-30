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


PageInternet* Requete::GetReferenceur( ) const
// Algorithme :
{
	return referenceur;
}	//----- Fin de GetReferenceur

PageInternet* Requete::GetCible ( ) const
// Algorithme :
{
	return cible;
}	//----- Fin de GetCible

//------------------------------------------------- Surcharge d'opérateurs
Requete & Requete::operator = ( const Requete & uneRequete )
// Algorithme :	Si on n'est pas en train de faire uneRequete = uneRequete,
//				on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de uneRequete.
//				On utilisera la surcharge de = pour les PageInternets.
{
	if ( this != &uneRequete )
	{
		referenceur = new PageInternet( *uneRequete.referenceur );
		cible = new PageInternet( *uneRequete.cible );
	}

	return *this;

}	//----- Fin de operator =

bool Requete::operator< ( const Requete & autreRequete ) const
// Algorithme :
{
	if ( referenceur->GetOutputComplet( ) < autreRequete.referenceur->GetOutputComplet( ) )
	{
		if ( cible->GetOutputComplet( ) < autreRequete.cible->GetOutputComplet( ) )
		{
			return true;
		}
	}

	// Si on arrive ici, c'est que les strings des PageInternets cible & referenceur
	// de l'objet courant ne sont pas inferieures au sens lexicographique aux strings
	// des PageInternets de autreRequete
	return false;

}	//----- Fin de operator <

bool Requete::operator== ( const Requete & autreRequete ) const
{
	if ( referenceur->GetOutputComplet( ) == autreRequete.referenceur->GetOutputComplet( ) )
	{
		if ( cible->GetOutputComplet( ) == autreRequete.cible->GetOutputComplet( ) )
		{
			return true;
		}
	}

	// Si on arrive ici, c'est que les deux requetes ne sont pas equivalentes
	return false;

}	//----- Fin de operator ==


//-------------------------------------------- Constructeurs - destructeur
Requete::Requete ( const Requete & uneRequete ) :
	referenceur( nullptr ), cible( nullptr )
// Algorithme :	Construction a partir du constructeur par copie de PageInternet.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Requete>" << endl;
#endif

	referenceur = new PageInternet( *uneRequete.referenceur );
	cible = new PageInternet( *uneRequete.cible );

}	//----- Fin de Requete ( constructeur de copie )


Requete::Requete ( ) : referenceur( ), cible( )
// Algorithme :	Construction par defaut grace au constructeur par defaut de PageInternet.
{
#ifdef MAP
    cout << "Appel au constructeur de <Requete>" << endl;
#endif
}	//----- Fin de Requete

Requete::Requete ( const PageInternet& ref, const PageInternet& target ) :
	referenceur( nullptr ), cible( nullptr )
// Algorithme :	Construction a partir du constructeur de copie de PageInternet,
//				et allocation dynamique.
{
#ifdef MAP
	cout << "Appel au destructeur de <Requete>" << endl;
#endif

	referenceur = new PageInternet( ref );
	cible = new PageInternet( target );

}


Requete::~Requete ( )
// Algorithme :
{
#ifdef MAP
    cout << "Appel au destructeur de <Requete>" << endl;
#endif

	delete referenceur;
	delete cible;

} //----- Fin de ~Requete


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
