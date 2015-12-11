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
#include <cstddef>

#include "PageInternet.h"

//------------------------------------------------------------------ Types
typedef std::pair<PageInternet, int> ArcRequete;	// Un arc du graphe (requeteur, nombre d'acces)
typedef std::vector<ArcRequete> Arcs;				// Ensembles des arcs arrivant a un neoud donne
typedef Arcs::iterator IterateurArcs;				// Iterateur sur la structure precedente
typedef Arcs::const_iterator IterateurArcsConst;	// Iterateur constant sur la structure precedente

//------------------------------------------------------------------------ 
// R�le de la classe <GrapheRequetes>
// La classe GrapheRequete repr�sente un graphe de requ�tes de navigation internet
// qu'on peut trouver par exemple dans un fichier de journalisation.
// Elle stocke un ensemble de PageInternets qui sont les noeuds du graphe,
// et associe � chacun d'entre eux un ensemble de liens orient�s des noeuds exterieurs
// vers le noeud courant (= arc).
// Chaque PageInternet ne pourra �tre stock�e en tant que noeud qu'un seule et unique fois.
//------------------------------------------------------------------------ 

class GrapheRequetes : public std::map<PageInternet, Arcs>
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    int ExportFormatGraphViz ( const std::string& nomFichier ) const;
	// Mode d'emploi :	Ecrit l'instance courante sur le disque sous forme de graphe GraphViz (format .dot).
	//					Si le nom du fichier GraphViz nomFichier specifie ne se termine pas par ".dot",
	//					l'extension sera ajoutee.
	//					Retourne 0 si le graph a pu etre ecrit sur le disque,
	//					-1002 sinon.


//------------------------------------------------- Surcharge d'op�rateurs
	// Tout les operateurs de map<PageInternet, Arc> s'appliquent sans soucis a GrapheRequetes.
	// Pour operator[], il est � la charge de l'utilisateur de v�rifier l'int�grit� de l'Arcs retourn�.

//-------------------------------------------- Constructeurs - destructeur
    GrapheRequetes ( const GrapheRequetes& unGrapheRequetes );
    // Mode d'emploi (constructeur de copie) :	Consruit une nouvelle instance de GrapheRequetes
	//											a partir d'un GrapheRequetes existante unGrapheRequetes.
	//											L'objet instancie sera en tout point similaire a unGrapheRequetes.

    GrapheRequetes ( );
    // Mode d'emploi :	Instancie un objet de type GrapheRequete.

    virtual ~GrapheRequetes ( );
    // Mode d'emploi :	Detruit l'instance et libere la memoire. Appele automatiquement.

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
typedef GrapheRequetes::iterator IterateurGrapheRequetes;				// Iterateur sur GrapheRequetes
typedef GrapheRequetes::const_iterator IterateurGrapheRequetesConst;	// Iterateur constant sur GrapheRequetes

#endif // GRAPHEREQUETES_H
