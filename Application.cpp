/*************************************************************************
                           Application  -  description
                             -------------------
    début                : 23/11/2015
    copyright            : (C) 2015 par Pericas-Moya & Belletier
*************************************************************************/

//---------- Réalisation de la classe <Application> (fichier Application.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>

//------------------------------------------------------ Include personnel
#include "Application.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés
typedef pair<PageInternet*, int> AccesPage;
typedef list<AccesPage> MeilleuresPages;
typedef MeilleuresPages::iterator IterateurMeilleuresPages;

struct ComparaisonAccesPages
{
	bool operator() ( const AccesPage& ap1, const AccesPage& ap2 ) const
	{
		return ap1.second > ap2.second;
	}
};

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

int Application::Run ( int heure, const string& nomGraph )
// Algorithme :
{
	// Declarations des variables de traitement
	ifstream fichier(fichierEntree, ios::in);
	string lecture;
	string tamponRequete;
	string tamponRequeteur;
	size_t posTampon;
	const string STR_GET = string( "GET" );
	const size_t SIZE_STR_GET = STR_GET.length();

	// Verification que le fichier ai bien ete ouvert
	if ( !fichier )
	{
		// Si le fichier n'existe pas (mauvais chemin d'acces), fin de la methode
		cerr << "Fichier d'entree " + fichierEntree + " introuvable." << endl;
		return -1001;
	}

	// Lecture du fichier et remplissage du graph
	while ( getline ( fichier, lecture ) )		// Tant qu'il y a des lignes a lire
	{
		// Recherche des premiers elements qui nous interessent
		posTampon = lecture.find("[");
		posTampon = lecture.substr( posTampon ).find( ":" );
		// Si on choisi de ne garder que les requetes a une certaine heure
		if ( ( flags & ONE_HOUR ) == ONE_HOUR )
		{
			// Si l'heure n'est pas bonne, on saute la ligne
			if ( strtol( lecture.substr( posTampon + 1, 2 ).c_str( ), nullptr, 0 ) != heure )
			{
				continue;
			}
		}
		posTampon = lecture.find( STR_GET );
		// Si il ne s'agit pas d'une requete de type GET, on saute la ligne
		if ( posTampon != string::npos )
		{
			continue;
		}
		tamponRequete = lecture.substr( posTampon + SIZE_STR_GET + 1,
			lecture.substr( posTampon + SIZE_STR_GET + 1 ).find(" ") );
			// A partir de la tamponRequete contient l'url a laquelle on a voulu acceder
		posTampon = lecture.substr( posTampon ).find( "\"" );
			posTampon = lecture.substr( posTampon ).find( "\"" );
			// posTampon arrive au debut de l'url du requeteur
		tamponRequeteur = lecture.substr( posTampon, lecture.substr( posTampon ).find( "\"" ) );
			// tamponRequeteur contient l'url du requeteur

		// Remplissage graph
		remplirGraph( tamponRequete, tamponRequeteur );
	}

	// Ecriture du graphe sur le disque au format .dot si l'option a ete specifiee
	if ( ( flags & DRAW_GRAPH ) == DRAW_GRAPH )
	{
		return ecrireGraph( "placeholder" );		// On renvoie le code retour de ecrireGraph qui aura cree ou non le fichier .dot
	}
	else
	// Sinon, affichage des dix pages les plus consultees
	{
		afficherResultats( );
	}

	return 0;
}

void Application::SetFlags ( Uint16 newFlags )
// Algorithme :
{
	flags = newFlags;

}	//----- Fin de SetFlags

//------------------------------------------------- Surcharge d'opérateurs
Application& Application::operator = ( const Application & uneApplication )
// Algorithme :	Si on n'est pas en train de faire uneApplication = uneApplication,
//				on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de uneApplication.
//				On utilisera la surcharge de = pour les maps, strings et Uint16.
{
	if ( this != &uneApplication )
	{
		fichierEntree = uneApplication.fichierEntree;
		graph = uneApplication.graph;
		flags = uneApplication.flags;
	}
	return *this;

}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Application::Application ( const Application & uneApplication ) :
	fichierEntree( uneApplication.fichierEntree ),
	graph( uneApplication.graph ), flags( uneApplication.flags )
// Algorithme :	Utilisation des constructeurs de copie de string, map et Uint16 (uint16_t).
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Application>" << endl;
#endif
	// Rien de plus a faire ici

} //----- Fin de Application (constructeur de copie)


Application::Application ( string fichierIn, Uint16 f ) :
	fichierEntree( fichierIn ), graph( ), flags( f )
// Algorithme :	Instanciation a partir des constructeurs de string, map et Uint16 (uint16_t).
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Application>" << endl;
#endif

} //----- Fin de Application


Application::~Application ( )
// Algorithme :	Liberation memoire. Rien de particulier a faire, les destructeurs de tout
//				les elements feront parfaitement leur travail.
{
#ifdef MAP
    cout << "Appel au destructeur de <Application>" << endl;
#endif
	// Pas d'allocation dynamique.

}	//----- Fin de ~Application

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
int Application::ecrireGraph (std::string filename )
// Algorithme :
{
	// TODO :	implanter l'ecriture du graph
	// Declaration des variables
    ofstream fichierGraphe;
    IterateurGraph iteGraphe;
    Arcs::iterator iteArc;
    // Ouverture du fichier et ecriture des lignes d'en-tête qui ne dependent pas du graphe
    fichierGraphe.open(filename);
    if ( fichierGraphe.is_open() )
    {
        fichierGraphe<<"//Fichier "<< filename<< "\n\n\n\n";
        fichierGraphe<<"digraph {\n";
        // Ecriture des lignes propres au graphe
        for ( iteGraphe = graph.begin(); iteGraphe != graph.end(); iteGraphe++ )
        {
            // ecriture du noeud
            fichierGraphe<< "\t"<<iteGraphe->first.GetOutputComplet();
            if(iteGraphe->first.GetEstIsole() == true)
            {
                fichierGraphe << "[label = " << iteGraphe->first.GetOutputExt() << "]";
            }
            fichierGraphe<< ";\n";
            // ecriture des aretes
            for ( iteArc = iteGraphe->second.begin(); iteArc != iteGraphe->second.end(); iteArc++ )
            {
                fichierGraphe << iteArc->GetPageInternet()->GetOutputComplet() << " -> ";
                fichierGraphe << iteGraphe->first.GetOutputComplet();
                fichierGraphe << " [label = " << iteArc->GetNombreAcces() << "];\n";
            }
        }


        // pied de page -> ne depend pas du graphe
        fichierGraphe<<"}";
        fichierGraphe.close();
        return 0;
    }
	return -1002;		// En cas d'erreur lors de l'ecriture
}	//----- Fin de ecrireGraph

void Application::afficherResultats ( )
// Algorithme :	Parcours sequentiel du graph :
//				Pour chaque noeud, on calcul le nombre total de fois ou on a accede a celui-ci en additionnant
//				le nombre d'acces de chaque arc (=Requete.nombreAcces).
//				Si on n'a pas encore atteint le nombre de resultats souhaite, on insere le noeud dans une std::list
//				sans se poser de questions (list permet un tri plus rapide que vector).
//				Sinon, on tri la liste par ordre decroissant (grace au foncteur ComparaisonAccesPages) du nombre
//				d'acces total, et si il s'avere que le nombre d'acces total au noeud courant est superieur a celui
//				du dernier element de la liste, on l'insere eu queue, on retri la liste, et on supprime le dernier
//				element.
//				Lorsqu'on a parcouru tout les noeuds, on trie la liste uniquement si elle n'a pas ete triee
//				(= si on n'a jamais atteint le nombre de resultats souhaites), puis on affiche les urls de chacune
//				des pages qui la compose, ainsi que le nombre d'acces fait a chaque page.
// Complexite :	O(n*m), mais m est en general tres petit.
//				De plus, cette operation n'est realisee qu'une seule et unique fois par appel a Run(),
//				et seulement si le flag DRAW_GRAPH n'est pas present.
//				Si on avait trie notre map (= graph) par le nombre d'acces fait a chaque noeud, cette operation
//				aurait ete en O(1), mais les autres operations (recherche, insertion) auraient ete
//				plus longues et moins pertinentes : il est plus evident de trier les PageInternets par leur url,
//				fixe, que par le nombre d'acces, qui varie tout au long de l'application (parcours du fichier de logs).
//				Cette variation aurait meme certainement introduit des dysfonctionnements.
{
	const int NOMBRE_RESULTATS = 10;		// Si un jour on veut en afficher +/-, il suffit de changer ici
	MeilleuresPages meilleursResultats;

	// Parcours du graph pour trouver les dix pages les plus consultees
	for ( IterateurGraph itg = graph.begin(); itg != graph.end(); itg++ )
	{
		// Déclarations variables pour plus de praticite
		int i = 0;
		int taille = itg->second.size();
		int nombreAcces = itg->second[i].GetNombreAcces( );

		int somme = 0;
		// Calcul du nombre total d'acces
		while ( i++ < taille )
		{
			somme += nombreAcces;
		}

		// Si on n'a pas encore le nombre maximum de resultats, insertion
		if ( meilleursResultats.size( ) < NOMBRE_RESULTATS )
		{
			meilleursResultats.push_back( AccesPage( itg->second[i].GetPageInternet( ), nombreAcces ) );
		}
		// Sinon, on verifie que c'est un actuel meilleur resultat
		else
		{
			meilleursResultats.sort( ComparaisonAccesPages( ) );

			// Si c'est une des NOMBRE_RESULTATS pages les plus consultees (strictement), insertion
			if ( nombreAcces > meilleursResultats.rbegin()->second )
			{
				// On l'ajoute
				meilleursResultats.push_back( AccesPage( itg->second[i].GetPageInternet( ), nombreAcces ) );
				// On retri (tres rapide)
				meilleursResultats.sort( ComparaisonAccesPages( ) );
				// On supprime le dernier
				meilleursResultats.pop_back( );
			}
		}	//----- Fin de if ( meilleursResultats.size( ) < NOMBRE_RESULTATS ) else
	}	//----- Fin de for (IterateurGraph)

	// Si il y a moins de NOMBRE_RESULTATS noeuds, la structure de resultats n'est pas triee
	if ( meilleursResultats.size() < NOMBRE_RESULTATS )
	{
		meilleursResultats.sort( ComparaisonAccesPages( ) );	// On trie
	}

	// Affichage
	for ( IterateurMeilleuresPages itmp = meilleursResultats.begin( ); itmp != meilleursResultats.end( ); itmp ++ )
	{
		cout << itmp->first->GetOutputComplet( ) << ends << itmp->second << endl;
	}

}	//----- Fin de afficherResultats

void Application::remplirGraph ( const string& requete, const string& requeteur )
// Algorithme :	Pour le moment, les requeteur d'un type indesirable sont geres comme suit :
//				On insere a leur place une Requete avec un pointeur vers une PageInternet
//				qui a l'url "Autre Type Requeteur".
//				La page requetrice sera inseree en tant que noeud sauf si elle est d'un type
//				qui doit être exclu de l'analyse.
// TODO : mettre un retour
{
	const string STR_REQUETEUR_EXCLU = "Autre Type Requeteur";
	Arcs::iterator ita;
	PageInternet pageRequete( requete );
	PageInternet pageRequetrice( requeteur );

	// Si le flag de l'option -e est present, on verifie que les deux PageInternets sont du bon type
	if ( ( flags & E_OPTION ) == E_OPTION )
	{
		if ( IMAGE.find( pageRequete.GetType( ) ) != string::npos
			|| SCRIPT.find( pageRequete.GetType( ) ) != string::npos )
		{
			return;		// On ne traite pas la ligne
		}
		if ( IMAGE.find( pageRequete.GetType( ) ) != string::npos
			|| SCRIPT.find( pageRequete.GetType( ) ) != string::npos )
		{
			pageRequetrice = PageInternet ( STR_REQUETEUR_EXCLU );
		}
	}

	// Si la page d'url requete n'est pas encore presente en tant que noeud
	if ( graph.find( pageRequete ) == graph.end( ) )
	{
		// Insertion de la clef
		Arcs & arcs = graph[pageRequete];	// NB :	On cree une reference en meme temps pour eviter
											//		de refaire la recherche dans graph a chaque fois,
											//		meme si celle-ci se fait en O(log2(n))

		// Que le requeteur soit d'un type indesirable ou non, c'est le meme algorithme d'insertion
		ita = find( arcs.begin( ), arcs.end( ), Requete( &pageRequetrice ) );

		// Si le requeteur n'est pas present dans le vecteur d'arcs
		if ( ita == arcs.end( ) )
		{
			arcs.push_back( Requete( &pageRequetrice ) );	// On l'insere
		}
		else
		{
			ita->IncrementeNombreAcces( );
		}

	}	//----- Fin de if (pageRequete est deja un noeud)

	// Si la page d'url requeteur est du bon type
	if ( pageRequetrice.GetOutputComplet( ) != STR_REQUETEUR_EXCLU )
	{
		// Si elle n'est pas encore presente en tant que noeud
		if ( graph.find( pageRequetrice ) == graph.end( ) )
		{
			graph[pageRequetrice];	// On l'insere
		}
	}

}	//----- Fin de remplirGraph

//------------------------------------------------------- Méthodes privées
