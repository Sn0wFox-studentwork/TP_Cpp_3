/*************************************************************************
                           GrapheRequetes  -  description
                             -------------------
    début                : 23/11/2015
    copyright            : (C) 2015 par Pericas-Moya & Belletier
*************************************************************************/

//---------- Réalisation de la classe <GrapheRequetes> (fichier GrapheRequetes.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "GrapheRequetes.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type GrapheRequetes::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


int GrapheRequetes::ExportFormatGraphViz( string fichier )
// Algorithme :
{
	// Declaration des variables
    IterateurGrapheRequetes iteGraphe;
    IterateurArcs iteArc;
	ofstream fichierGraphe;
	string nomFichier = fichier;

	if ( nomFichier.find(".dot") == string::npos )
	{
		nomFichier += ".dot";
	}
	
	fichierGraphe.open( nomFichier );	// Fonctionne seulement avec c++11 ; nomFichier.c_str() sinon

    // Ecriture des lignes d'en-tête qui ne dependent pas du graphe, si le fichier est ouvert
    if ( fichierGraphe )
    {
        fichierGraphe << "//Fichier " << nomFichier << "\n\n\n\n";
        fichierGraphe << "digraph {\n";
        // Ecriture des lignes propres au graphe
        for ( iteGraphe = this->begin( ); iteGraphe != this->end( ); iteGraphe++ )
        {
            // ecriture du noeud
            fichierGraphe<< "\t"<<iteGraphe->first.GetOutputComplet();
            if( iteGraphe->first.GetEstIsole( ) == true )
            {
                fichierGraphe << "[label = " << iteGraphe->first.GetOutputExt( ) << "]";
            }
            fichierGraphe << ";\n";
            // ecriture des aretes
            for ( iteArc = iteGraphe->second.begin( ); iteArc != iteGraphe->second.end( ); iteArc++ )
            {
                fichierGraphe << iteArc->GetRequeteur( )->GetOutputComplet( ) << " -> ";
                fichierGraphe << iteGraphe->first.GetOutputComplet( );
                fichierGraphe << " [label = " << iteArc->GetNombreAcces( ) << "];\n";
            }
        }

        // pied de page -> ne depend pas du graphe
        fichierGraphe << "}";
        fichierGraphe.close( );
        return 0;
    }
	return -1002;		// En cas d'erreur lors de l'ecriture
}	//----- Fin de ExportFormatGraphViz

//-------------------------------------------- Constructeurs - destructeur
GrapheRequetes::GrapheRequetes ( const GrapheRequetes & unGrapheRequetes ) : map( unGrapheRequetes )
// Algorithme :	utilisation du constructeur de copie de map<PageInternet, Arcs>.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GrapheRequetes>" << endl;
#endif
	// Pas d'autres attributs

}	//----- Fin de GrapheRequetes (constructeur de copie)


GrapheRequetes::GrapheRequetes ( ) : map( )
// Algorithme :	utilisation du constructeur par defaut de map<PageInternet, Arcs>
{
#ifdef MAP
    cout << "Appel au constructeur de <GrapheRequetes>" << endl;
#endif

}	//----- Fin de GrapheRequetes


GrapheRequetes::~GrapheRequetes ( )
// Algorithme :	le destructeur de map sera appelé automatiquement.
{
#ifdef MAP
    cout << "Appel au destructeur de <GrapheRequetes>" << endl;
#endif
	// Pas d'allocation dynamique

}	//----- Fin de ~GrapheRequetes


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
