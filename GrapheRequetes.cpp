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

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int GrapheRequetes::ExportFormatGraphViz( const string& fichier ) const
// Algorithme :
{
	// Taille maximale de l'url d'une age pour exportation dans le graphe
	const size_t SIZE_URL_MAX = 30;		// Au dela, l'url sera tronquee et on lui adjoindra [...]

	// Declaration des variables de manipulation du graphe :
    IterateurGrapheRequetesConst iteGraphe;
    IterateurArcsConst iteArc;
	// Variable permettant d'adjoindre ".dot" au nom de fichier si necessaire :
	string nomFichier = fichier;

	if ( nomFichier.find(".dot") == string::npos )
	{
		nomFichier += ".dot";
	}

	ofstream fichierGraphe( nomFichier.c_str( ) );	// string fonctionne seulement avec c++11 ; nomFichier.c_str() sinon

    // Ecriture des lignes d'en-tête qui ne dependent pas du graphe, si le fichier est ouvert
    if ( fichierGraphe )
    {
        fichierGraphe << "//Fichier " << nomFichier << "\n\n\n\n";
        fichierGraphe << "digraph {\n";

        // Ecriture des lignes propres au graphe
        for ( iteGraphe = this->begin( ); iteGraphe != this->end( ); iteGraphe++ )
        {
            // ecriture du noeud
			PageInternet pageUrlTronquee1( iteGraphe->first );
			if ( pageUrlTronquee1.GetUrl( ).size() > SIZE_URL_MAX )
			{
				pageUrlTronquee1 = PageInternet( pageUrlTronquee1.GetUrl( ).substr( 0, SIZE_URL_MAX ) + "[...]" );
			}
            fichierGraphe<< "\t" << pageUrlTronquee1.GetOutputComplet( );
            if( iteGraphe->first.GetEstIsole( ) == true )
            {
                fichierGraphe << "[label = " << iteGraphe->first.GetOutputExt( ) << "]";
            }
            fichierGraphe << ";\n";
            // ecriture des aretes
            for ( iteArc = iteGraphe->second.begin( ); iteArc != iteGraphe->second.end( ); iteArc++ )
            {
                PageInternet pageUrlTronquee2( iteArc->first );
                if ( pageUrlTronquee2.GetUrl( ).size() > SIZE_URL_MAX )
                {
                    pageUrlTronquee2 = PageInternet( pageUrlTronquee2.GetUrl( ).substr( 0, SIZE_URL_MAX ) + "[...]" );
                }
                fichierGraphe << "\t" ;
                fichierGraphe << pageUrlTronquee2.GetOutputComplet( ) << " -> ";
                fichierGraphe << pageUrlTronquee1.GetOutputComplet( );
                fichierGraphe << " [label = " << iteArc->second << "];\n";
            }
        }

        // pied de page -> ne depend pas du graphe
        fichierGraphe << "}";
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
