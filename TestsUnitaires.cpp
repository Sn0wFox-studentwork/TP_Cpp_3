#include "TestsUnitaires.h"

#include <iostream>

using namespace std;

void Tests( )
{
	// Si la clef n'existe pas, la valeur prend une valeur nulle (fonction du type de la clef)
	GrapheRequetes ryan;
	PageInternet p1( "hi" );
	PageInternet p2( "hi2" );
	ryan[p1];
	ryan[p2];

	PageInternet p("http://monwebsite/trololo.html");

	if ( ryan.find( p ) == ryan.end( ) )
	{
		cout << p.GetOutputComplet( ) << " non trouve !" << endl;
		cout << p.GetRacine( ) << endl;
	}

	for ( IterateurGrapheRequetes it = ryan.begin( ); it != ryan.end( ); it++ )
	{
		cout << it->first.GetOutputComplet( ) << endl;
	}
}

void TestFlags ()
{
	Uint16 flags = FLAG_ALL_FLAGS;

	// Flags unitaires : la comparaison est inutile
	if ( flags & FLAG_ONE_HOUR )
	{
		cout << "FLAG_ONE_HOUR !" << endl;
	}
	if ( flags & FLAG_DRAW_GRAPH )
	{
		cout << "FLAG_DRAW_GRAPH !" << endl;
	}
	// Flags composites : la comparaison est obligatoire (parenthese pour enlever un warning du compilo)
	if ( ( flags & FLAG_E_OPTION ) == FLAG_E_OPTION )
	{
		cout << "FLAG_E_OPTION !" << endl;
	}

	flags = FLAG_NO_IMAGE;
	cout << "Flags : " << (int)flags << " FLAG_NO_IMAGE : " << (int)FLAG_NO_IMAGE << " FLAG_NO_SCRIPT : " << (int)FLAG_NO_SCRIPT;
	cout << " FLAG_E_OPTION : " << (int)FLAG_E_OPTION << endl;
	if ( flags & FLAG_NO_IMAGE )
	{
		cout << "FLAG_NO_IMAGE !" << endl;
	}
	if ( !( flags & FLAG_NO_SCRIPT ) )
	{
		cout << "Pas FLAG_NO_SCRIPT !" << endl;
	}
	// Utilisation de flags composites : utiliser l'operateur == apres extraction
	if ( ( flags & FLAG_E_OPTION ) == FLAG_E_OPTION)
	{
		cout << "FLAG_E_OPTION !" << endl;
	}

}

void TestFind( )
{
	string s = " lh 7 trolololo 7 youpi";
	cout << s.find("7", 1, 1) << endl;
	string lecture = "... - - [...] \"GET /temps/trololo/page.html HTTP/1.1\" 200 12325";

	size_t posTampon = lecture.find( "GET" );
	cout << posTampon;
	// Si il ne s'agit pas d'une requete de type GET, on saute la ligne
	if (posTampon == string::npos)
	{
		cout << "rate !";
		return;
	}
	string tampon = lecture.substr ( posTampon + string( "GET " ).length( ),
		lecture.substr( posTampon + string( "GET " ).length( ) ).find( " " ) );
	cout << tampon << "-" << endl;

}

void TestTri()
{
	PageInternet p1( "page1.html" );
	PageInternet p2( "page2.html" );
	PageInternet p3( "page3.html" );
	MeilleuresPages mp;
	mp.push_back( AccesPage( p1, 7 ) );
	mp.push_back( AccesPage( p2, 9 ) );
	mp.push_back( AccesPage ( p3, 3 ) );

	for ( IterateurMeilleuresPages i = mp.begin( ); i != mp.end( ); i++ )
	{
		cout << i->first.GetOutputComplet( ) << ends << i->second << endl;
	}

	mp.sort( ComparaisonAccesPages( ) );

	for ( IterateurMeilleuresPages i = mp.begin( ); i != mp.end( ); i++ )
	{
		cout << i->first.GetOutputComplet( ) << ends << i->second << endl;
	}
}

void TestGraph( )
// Verifie que les pages sont bien clasees par ordre lexicographique
{
	GrapheRequetes g;
	PageInternet p1( "page1.html" );
	PageInternet p2( "page2.html" );
	PageInternet p3( "page3.html" );
	PageInternet p4( "monstyle.css" );

	Arcs & a = g[p3];
	a.push_back( ArcRequete( &p1 ) );
	g[p4];
	g[p1];
	g[p2];

	for ( IterateurGrapheRequetes itg = g.begin( ); itg != g.end (); itg++ )
	{
		cout << itg->first.GetOutputComplet( ) << endl;
	}

	cout << "g[p3][0].GetPageInternet->GetOutputComplet( ) via ref : "
		<< a[0].GetRequeteur( )->GetOutputComplet( ) << endl;
}

void TestFichier( )
{
	ifstream fichier( "anonyme2.log", ios::in );
	string lecture;
	getline( fichier, lecture );
	cout << lecture << endl;
}

void TestPrintResultats( )
{
	string fichier( "anonyme2.log" );
	string lecture;
	Application app( fichier, FLAG_NO_FLAGS );
	cout << app.Run( );

}
