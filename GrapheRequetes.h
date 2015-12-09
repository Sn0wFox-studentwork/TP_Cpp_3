/*************************************************************************
                           GrapheRequetes  -  description
                             -------------------
    d�but                : 23/11/2015
    copyright            : (C) 2015 par Pericas-Moya & Belletier
*************************************************************************/

//---------- Interface de la classe <GrapheRequetes> (fichier GrapheRequetes.h) ------
#if ! defined ( GRAPHEREQUETES_H )
#define GRAPHEREQUETES_H

//--------------------------------------------------- Interfaces utilis�es
#include <map>
#include <vector>
#include <string>

#include "PageInternet.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types
class ArcRequete
{
//-----------PUBLIC
public:
//-----------M�thodes publiques
	int GetNombreAcces ( ) const { return nombreAcces; }
	PageInternet* GetRequeteur ( ) const { return requeteur; }

//-----------Surcharge d'op�rateurs
	ArcRequete& operator++ ( )			// Prefix
	{
		++nombreAcces;
		return *this;
	}
	ArcRequete operator++ ( int )		// PostFix
	{
		ArcRequete exThis = *this;
		++(*this);
		return exThis;
	}
	bool operator== ( const ArcRequete& uneArc ) const
	// Algorithme :
	{
		return *requeteur == *uneArc.requeteur;
	}	//----- Fin de operator==

//-----------Constructeur
	ArcRequete( PageInternet* const pageRequetrice ) : requeteur( pageRequetrice ), nombreAcces( 1 )
	{
#ifdef MAP
		cout << "Appel au constructeur de copie de <ArcRequete>" << endl;
#endif
	}

//-----------PROTEGE
protected:
//-----------Attributs
	PageInternet* requeteur;
	int nombreAcces;

//-----------PRIVE
private:
//-----------Classe Amie
	friend class Grapherequetes;
};

typedef std::vector<ArcRequete> Arcs;
typedef Arcs::iterator IterateurArcs;

//------------------------------------------------------------------------ 
// R�le de la classe <GrapheRequetes>
//
//
//------------------------------------------------------------------------ 

class GrapheRequetes : public std::map<PageInternet, Arcs>
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    int ExportFormatGraphViz ( std::string nomFichier );
	// Mode d'emploi :	Retourne 0 si le graph a pu etre ecrit sur le disque,
	//					-1002 sinon.


//------------------------------------------------- Surcharge d'op�rateurs
	// Tout les operateurs de map<PageInternet, Arc> s'appliquent sans soucis a GrapheRequetes.


//-------------------------------------------- Constructeurs - destructeur
    GrapheRequetes ( const GrapheRequetes & unGrapheRequetes );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    GrapheRequetes ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~GrapheRequetes ( );
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

private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <GrapheRequetes>
typedef GrapheRequetes::iterator IterateurGrapheRequetes;

#endif // GRAPHEREQUETES_H
