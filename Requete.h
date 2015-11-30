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
// La classe requete permet de modeliser une requete presente dans un journal
// de logs de navigateur web. Elle possede deux PageInternets :
// Refereceur qui represente la page sur laquelle l'utilisateur etait lorsqu'il a clique.
// Cible qui represente la page ou il s'est rendu grace a son clic.
// Requete possede egalement d'autres informations sur la requete effectuee :
// sa date, l'IP de la machine et le nom de l'utilisateur.
// 
// Elle utilise l'allocation dynamique pour ses PageInternets, ce qui permet de ne pas saturer
// la pile lorsqu'on traite des milliers de requetes.
// TODO : ne pas mettre la derniere phrase ici, mais c'est pour s'en souvenir.
// 
//------------------------------------------------------------------------ 

class Requete
{

//----------------------------------------------------------------- PUBLIC
public:

//----------------------------------------------------- Méthodes publiques
	PageInternet* GetReferenceur ( ) const;
	PageInternet* GetCible ( ) const;
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//


//------------------------------------------------- Surcharge d'opérateurs
	Requete &operator = ( const Requete &unRequete );
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

	Requete ( const PageInternet& referenceur, const PageInternet& cible );
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
	PageInternet* referenceur;
	PageInternet* cible;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Requete>

#endif // REQUETE_H
