/*************************************************************************
                           Application  -  description
                             -------------------
    d�but                : 23/11/2015
    copyright            : (C) 2015 par Pericas-Moya & Belletier
*************************************************************************/

//---------- R�alisation de la classe <Application> (fichier Application.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <cstdint>

//------------------------------------------------------ Include personnel
#include "Application.h"

//------------------------------------------------------------- Constantes
//#define MAP
// Constantes evitant la redondance et permettant plus de modularite
const string STR_GOOD_REQUESTS = string( "200" );
const string STR_DIRECT_REQUEST = string( "-" );
const string STR_DOUBLEQUOTE = string( "\"" );
const string STR_GET = string( "GET" );
const size_t SIZE_STR_GET = STR_GET.length( );
const size_t SIZE_STR_CODERETOUR = 3;

//----------------------------------------------------------- Types priv�s
typedef pair<PageInternet, int> AccesPage;								// Permet de modeliser le nombre d'acces a une page particuliere
typedef list<AccesPage> MeilleuresPages;								// Permet de lister les pages les plus consultees
typedef MeilleuresPages::iterator IterateurMeilleuresPages;				// Iterateur sur le type de liste precedent
typedef MeilleuresPages::const_iterator IterateurMeilleuresPagesConst;	// Iterateur constant sur le type de liste precedent

// Foncteur permettant de comparer les AccesPages
struct ComparaisonAccesPages
// Comparaion via superiorite de l'entier de la pair (= nombre d'acces)
{
	bool operator() ( const AccesPage& ap1, const AccesPage& ap2 ) const
	{
		return ap1.second > ap2.second;
	}
};

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

int Application::Run ( const string& nomGraph, int heure )
// Algorithme :	On tente d'ouvrir le fichier en lecture, sans quoi on termine la methode avec le code -1001.
//				On commence ensuite a parser le fichier, requete par requete :
//				On recupere l'heure a laquelle la requete a ete faite, et on choisi de conserver ou d'exclure
//				cette requete de l'analyse suivant si le flag FLAG_ONE_HOUR est present et si c'est l'heure qu'on recherche.
//				On recupere ensuite le type de la requete ; s'il ne s'agit pas d'une requete de type GET, on saute la
//				ligne. Sinon, on recupere les urls du requeteur et du requete qu'on complete eventuellement pour
//				qu'elles soient absolues, puis on rempli notre structure de graph.
//				C'est la methode remplirGraph qui pour l'instant gere l'option -e.
//				Une fois le fichier analyse, si le flag FLAG_DRAW_GRAPH est present, on ecrit le graph sur le disque via
//				la methode ecrireGraph, dont on retourne le code de retour pour terminer la methode. Sinon,
//				on affiche les 10 pages les plus cnosultees et on retourne le code 0.
//				
// NB :			L'url du requeteur ne peut jamais etre relative. Elle ne peut etre qu'absolue ou nulle, c'est a dire "-".
{
	// Declarations des variables de traitement
	ifstream fichier( fichierEntree, ios::in );
	string derniereRacineNonNulle = "INCONNUE";		// Racine initiale	
	string lecture;
	string tamponRequete;
	string tamponRequeteur;
	size_t posTampon;

	// On verifie que le fichier a bien ete ouvert
	if ( !fichier )
	{
		// Si le fichier n'existe pas (mauvais chemin d'acces), fin de la methode
		cerr << "Fichier d'entree " + fichierEntree + " introuvable." << endl;
		return -1001;
	}

	// Lecture du fichier et remplissage du graph
	while ( getline ( fichier, lecture ) )		// Tant qu'il y a des lignes a lire
	{
		// Si on choisi de ne garder que les requetes a une certaine heure
		if ( ( flags & FLAG_ONE_HOUR ) == FLAG_ONE_HOUR )
		{
			// Recherche des premiers elements qui nous interessent
			posTampon = lecture.find( "[" );
			lecture = lecture.substr( posTampon );
			posTampon = lecture.find( ":" );
			lecture = lecture.substr( posTampon + 1 );	// lecture commence desormais au debut de l'heure de la requete

			// Si l'heure n'est pas bonne, on saute la ligne
			if ( atoi( lecture.substr( 0, lecture.find( ":" ) ).c_str( ) ) != heure )
			{
				continue;
			}
		}

		// Si il ne s'agit pas d'une requete de type GET
		posTampon = lecture.find( STR_DOUBLEQUOTE );
		lecture = lecture.substr( posTampon + 1 );
		if ( lecture.substr( 0, SIZE_STR_GET ) != STR_GET )
		{
			continue;	// On saute la ligne
		}

		// Prise de l'url de la page requetee
		tamponRequete = lecture.substr( SIZE_STR_GET + 1, lecture.find( STR_DOUBLEQUOTE ) - SIZE_STR_GET - 1 );
		tamponRequete = tamponRequete.substr( 0, tamponRequete.rfind(" ") );	// Recherche inversee qui evite les erreurs dues a des espaces dans l'url
																				// (ils auraient du etre remplaces par %20, mais c'est possible qu'il en reste)

		// Verification du code de retour de la requete
		posTampon = lecture.find( STR_DOUBLEQUOTE );
		lecture = lecture.substr( posTampon + 2 );		// lecture commence maintenant au debut du code de retour

		// Si on la requete n'a pas donne un des codes retour qui nous interesse
		posTampon = STR_GOOD_REQUESTS.find( lecture.substr( 0, SIZE_STR_CODERETOUR ) );
		if ( posTampon == string::npos )
		{
			continue;	// On saute la ligne
		}

		// Prise de l'url de la page requetrice
		posTampon = lecture.find( STR_DOUBLEQUOTE );
		lecture = lecture.substr( posTampon + 1 );
		tamponRequeteur = lecture.substr( 0, lecture.find( STR_DOUBLEQUOTE ) );

#ifdef MAP
		cout << "Requete : " << tamponRequete << " Requeteur : " << tamponRequeteur << endl;
#endif

		PageInternet pageRequete( tamponRequete );
		PageInternet pageRequetrice( tamponRequeteur );

		// Si la requete a une url relative
		if ( pageRequete.GetRacine( ) == "" )
		{
			pageRequete = PageInternet( STR_SERVER + tamponRequete );	// On prend la derniere racine non vide
			// NB : pas besoin d'inserer "/"
		}

		// On garde une trace de la derni�re racine non nulle, pour les futures requ�tes.
		derniereRacineNonNulle = pageRequete.GetUrl( );

		// Si le flag d'exclusion des images et scripts est present, on verifie que les deux PageInternets sont du bon type
		if ( ( flags & FLAG_EXCLUDE_OPTION ) == FLAG_EXCLUDE_OPTION )
		{
			if ( IMAGE.find( pageRequete.GetType( ) ) != string::npos
				|| SCRIPT.find( pageRequete.GetType( ) ) != string::npos )
			{
				continue;		// On ne traite pas la ligne :
								// que le requeteur soit d'un type acceptable ne nous interesse pas
			}
			if ( pageRequetrice.GetUrl( ) != STR_DIRECT_REQUEST
				&& ( IMAGE.find( pageRequetrice.GetType( ) ) != string::npos
				|| SCRIPT.find( pageRequetrice.GetType( ) ) != string::npos ) )
			{
				pageRequetrice = PageInternet ( STR_REQUETEUR_EXCLU );
			}
		}

		// Remplissage graph
		remplirGraph( pageRequete, pageRequetrice );

	}	//----- Fin de while ( ligne a lire )

	// Ecriture du graphe sur le disque au format .dot si l'option a ete specifiee
	if ( ( flags & FLAG_DRAW_GRAPH ) == FLAG_DRAW_GRAPH )
	{
		return graphe.ExportFormatGraphViz( nomGraph );		// On renvoie le code retour de ecrireGraph qui aura cree ou non le fichier .dot
	}
	else
	// Sinon, affichage des dix pages les plus consultees
	{
		afficherResultats( );
	}

	return 0;

}	//----- Fin de Run

void Application::SetFlags ( Uint16 newFlags )
// Algorithme :	Remplace les flags actuels par newFlags.
{
	flags = newFlags;

}	//----- Fin de SetFlags

//------------------------------------------------- Surcharge d'op�rateurs
Application& Application::operator = ( const Application & uneApplication )
// Algorithme :	Si on n'est pas en train de faire uneApplication = uneApplication,
//				on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de uneApplication.
//				On utilisera la surcharge de = pour les GrapheRequetes (map), strings et Uint16.
{
	if ( this != &uneApplication )
	{
		fichierEntree = uneApplication.fichierEntree;
		graphe = uneApplication.graphe;
		flags = uneApplication.flags;
	}
	return *this;

}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Application::Application ( const Application & uneApplication ) :
	fichierEntree( uneApplication.fichierEntree ),
	graphe( uneApplication.graphe ), flags( uneApplication.flags )
// Algorithme :	Utilisation des constructeurs de copie de string, map et Uint16 (uint16_t).
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Application>" << endl;
#endif
	// Rien de plus a faire ici

}	//----- Fin de Application (constructeur de copie)


Application::Application ( string fichierIn, Uint16 f ) :
	fichierEntree( fichierIn ), graphe( ), flags( f )
// Algorithme :	Instanciation a partir des constructeurs de string, map et Uint16 (uint16_t).
{
#ifdef MAP
    cout << "Appel au constructeur de <Application>" << endl;
#endif
	// Rien de plus a faire ici

}	//----- Fin de Application


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

//----------------------------------------------------- M�thodes prot�g�es

void Application::afficherResultats ( unsigned int nbResultats ) const
// Algorithme :	Parcours sequentiel du graph :
//				Pour chaque noeud, on calcul le nombre total de fois ou on a accede a celui-ci en additionnant
//				le nombre d'acces de chaque arc (=Arc.nombreAcces).
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
//				et seulement si le flag FLAG_DRAW_GRAPH n'est pas present.
//				Si on avait trie notre map (= graph) par le nombre d'acces fait a chaque noeud, cette operation
//				aurait ete en O(1), mais les autres operations (recherche, insertion) auraient ete
//				plus longues et moins pertinentes : il est plus evident de trier les PageInternets par leur url,
//				fixe, que par le nombre d'acces, qui varie tout au long de l'application (parcours du fichier de logs).
//				Cette variation aurait meme certainement introduit des dysfonctionnements ou ralentissements.
{
	MeilleuresPages meilleursResultats;

	// Parcours du graph pour trouver les dix pages les plus consultees
	for ( IterateurGrapheRequetesConst itg = graphe.begin( ); itg != graphe.end( ); itg++ )
	{
		// D�clarations variables pour plus de praticite
		int i = 0;
		int tailleArcs = itg->second.size();
		int nbTotalAcces = 0;

		// Calcul du nombre total d'acces
		while ( i < tailleArcs )
		{
			nbTotalAcces += itg->second[i].second;
			i++;
		}

		// Si on n'a pas encore le nombre maximum de resultats, insertion
		if ( meilleursResultats.size( ) < nbResultats )
		{
			meilleursResultats.push_back( AccesPage( PageInternet( itg->first ), nbTotalAcces ) );
		}
		// Sinon, on verifie que c'est un actuel meilleur resultat
		else
		{
			meilleursResultats.sort( ComparaisonAccesPages( ) );

			// Si c'est une des NOMBRE_RESULTATS pages les plus consultees (strictement), insertion
			if ( nbTotalAcces > meilleursResultats.rbegin()->second )
			{
				// On l'ajoute
				meilleursResultats.push_back( AccesPage( PageInternet( itg->first ), nbTotalAcces ) );
				// On retri (tres rapide)
				meilleursResultats.sort( ComparaisonAccesPages( ) );
				// On supprime le dernier
				meilleursResultats.pop_back( );
			}
		}	//----- Fin de if ( meilleursResultats.size( ) < NOMBRE_RESULTATS ) else
	}	//----- Fin de for ( IterateurGraph )

	// Si il y a moins de nbResultats noeuds, la structure de resultats n'est pas triee
	if ( meilleursResultats.size( ) < nbResultats )
	{
		meilleursResultats.sort( ComparaisonAccesPages( ) );	// On trie
	}

	// Affichage
	if ( meilleursResultats.begin( ) == meilleursResultats.end( ) )
	{
		cout << "Aucun resultat" << endl;
	}
	for ( IterateurMeilleuresPagesConst itmp = meilleursResultats.begin( ); itmp != meilleursResultats.end( ); itmp ++ )
	{
		cout << itmp->first.GetUrl() << " (" << itmp->second << " hits)" << endl;
	}

}	//----- Fin de afficherResultats

void Application::remplirGraph ( const PageInternet& pageRequetee, const PageInternet& pRequetrice )
// Algorithme :	Insere la page requetee en tant que noeud si elle n'est pas deja presente,
//				et cree une reference vers elle dans tout les cas.
//				Insere la page requetrice en tant qu'Arc, ou incremente son nombre d'acces si elle existe deja
//				en tant que telle.
//				Insere la page requetrice en tant que noeud sauf si elle est d'un type qui doit
//				�tre exclu de l'analyse.
{
	Arcs::iterator ita;
	PageInternet pageRequetrice( pRequetrice );		// Pour manipuler une page requetrice a ne pas analyser

	// Que la page d'url requete soit presente en tant que noeud ou pas, le code reste inchange
	// Il en va de m�me pour l'exclusion ou non de la page requetrice
	
	Arcs& arcs = graphe[pageRequetee];	// NB :	Soit la page existe en tant que noeud, 
										//		auquel cas on creee juste une reference,
										//		soit elle n'existe pas,
										//		auquel cas elle est insere et on cree une reference.
										//		Cette reference permet de ne pas refaire la rechrche dans la map
										//		a chaque fois, bien qu'en O(log2(n))

	// Que le requeteur soit d'un type indesirable ou non, c'est le meme algorithme d'insertion
	for ( ita = arcs.begin( ); ita != arcs.end( ); ita++ )
	{
		if ( ita->first == pageRequetrice )
		{
			break;
		}
	}		// NB :	pas possible d'utiliser l'algorithme find qui comparerait les deux membres de ArcRequete.
			//		En effet, on ne peut pas predire le nombre d'acces

	// Si le requeteur n'est pas present dans le vecteur d'arcs
	if ( ita == arcs.end( ) )
	{
		arcs.push_back( ArcRequete( pageRequetrice, 1 ) );	// On l'insere
	}
	else
	{
		ita->second++;
	}

	/*// Si la page d'url requeteur est du bon type
	if ( pageRequetrice.GetUrl( ) != STR_REQUETEUR_EXCLU )
	{
		graphe[pageRequetrice];	// On l'insere si elle n'est pas presente en tant que noeud,
								// sinon rien ne se passe.
	}*/

}	//----- Fin de remplirGraph