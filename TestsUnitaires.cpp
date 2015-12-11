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
	a.push_back( ArcRequete( p1, 1 ) );
	g[p4];
	g[p1];
	g[p2];

	for ( IterateurGrapheRequetes itg = g.begin( ); itg != g.end (); itg++ )
	{
		cout << itg->first.GetOutputComplet( ) << endl;
	}

	cout << "g[p3][0].GetPageInternet->GetOutputComplet( ) via ref : "
		<< a[0].first.GetOutputComplet( ) << endl;
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

void TestGrosFichierGraph( )
{
	cout << "Test anonyme.log" << endl;
	Application a("anonyme.log", FLAG_DRAW_GRAPH);
	a.Run();

}

void TestPageInternetGets ( )
{
    //doit cout 20 lignes de True
	PageInternet p1("http://www.monsite.com/d1/rsc.type");
	PageInternet p2("http://www.monsite.com");
	PageInternet p3("-");
	PageInternet p4("monsite");
	PageInternet p5("/rsc.type");
	//Tests sur P1
	cout << (p1.GetRacine() == "http://www.monsite.com") << endl;
	cout << (p1.GetExtension() == "/d1/rsc.type") << endl;
	cout << (p1.GetOutputComplet() == "\"http:/\\/www.monsite.com/d1/rsc.type\"") << endl;
	cout << (p1.GetOutputExt() == "\"/d1/rsc.type\"") << endl;
	cout << (p1.GetType() == ".type") << endl;
	//Tests sur P2
	cout << (p2.GetRacine() == "http://www.monsite.com") << endl;
	cout << (p2.GetExtension() == "") << endl;
	cout << (p2.GetOutputComplet() == "\"http:/\\/www.monsite.com\"") << endl;
	cout << (p2.GetOutputExt() == "\"\"") << endl;
	cout << (p2.GetType() == ".com") << endl;
	//Tests sur P3
	cout << (p3.GetRacine() == "-") << endl;
	cout << (p3.GetExtension() == "") << endl;
	cout << (p3.GetOutputComplet() == "\"-\"") << endl;
	cout << (p3.GetOutputExt() == "\"\"") << endl;
	cout << (p3.GetType() == "") << endl;
	//Tests sur P4
	cout << (p4.GetRacine() == "monsite") << endl;
	cout << (p4.GetExtension() == "") << endl;
	cout << (p4.GetOutputComplet() == "\"monsite\"") << endl;
	cout << (p4.GetOutputExt() == "\"\"") << endl;
	cout << (p4.GetType() == "") << endl;
	//Tests sur P5
	cout << (p5.GetRacine() == "") << endl;
	cout << (p5.GetExtension() == "/rsc.type") << endl;
	cout << (p5.GetOutputComplet() == "\"/rsc.type\"") << endl;
	cout << (p5.GetOutputExt() == "\"/rsc.type\"") << endl;
	cout << (p5.GetType() == ".type") << endl;

}

void TestPageInternetOp ( )
{
    //doit cout 6 lignes de True
	PageInternet p1("abcde");
	PageInternet p2("abcde");
	PageInternet p3("bacde");
	PageInternet p4("aabcd");
	cout << (p1 == p2) << endl;
	cout << !(p1 < p2) <<endl;
	cout << !(p1 == p3) << endl;
	cout << (p1 < p3) <<endl;
	cout << !(p1 == p4) << endl;
	cout << !(p1 < p4) <<endl;
}

void TestPageInternet ( )
{
    //doit cout 26 lignes de true
	TestPageInternetGets();
	TestPageInternetOp();

}

void TestGrapheExport ( )
{
	//Test 1 graphe vide
	{
		GrapheRequetes g;
		g.ExportFormatGraphViz("testsGraphe/out1.dot");
	}
	//Test 2 graphe à un sommet sans arêtes
	{
		GrapheRequetes g;
		PageInternet p1("http://site1.com/rsc.t");
		p1.SetEstIsole(false);
		g[p1];
		g.ExportFormatGraphViz("testsGraphe/out2.dot");
	}
	//Test 3 graphe à deux sommets et deux arêtes
	{
		GrapheRequetes g;
		PageInternet p1("http://site1.com/rsc.t");
		PageInternet p2("http://site1.com/rsc2.t");
		p1.SetEstIsole(false);
		p2.SetEstIsole(true);
		g[p1];
		g[p2];
		g[p1].push_back( ArcRequete( p2, 1 ) );
		g[p2].push_back( ArcRequete( p1, 5 ) );
		g.ExportFormatGraphViz("testsGraphe/out3.dot");
	}
	//Test 4 Plusieurs pages toujours isolées
	{
		GrapheRequetes g;
		PageInternet p1("http://site1.com/rsc1.t");
		PageInternet p2("http://site1.com/rsc2.t");
		PageInternet p3("http://site1.com/rsc3.t");
		PageInternet p4("http://site1.com/rsc4.t");
		PageInternet p5("http://site1.com/rsc5.t");
		p1.SetEstIsole(true);
		p2.SetEstIsole(true);
		p3.SetEstIsole(true);
		p4.SetEstIsole(true);
		p5.SetEstIsole(true);
		g[p1];
		g[p2];
		g[p3];
		g[p4];
		g[p5];
		g[p1].push_back( ArcRequete( p2, 1 ) );
		g[p1].push_back( ArcRequete( p3, 3 ) );
		g[p1].push_back( ArcRequete( p4, 7 ) );
		g[p4].push_back( ArcRequete( p5, 9 ) );
		g[p3].push_back( ArcRequete( p5, 2 ) );
		g[p2].push_back( ArcRequete( p1, 5 ) );
		g.ExportFormatGraphViz("testsGraphe/out4.dot");
	}
    //Test 5 Plusieurs pages jamais isolées
	{
	    GrapheRequetes g;
		PageInternet p1("http://site1.com/rsc1.t");
		PageInternet p2("http://site1.com/rsc2.t");
		PageInternet p3("http://site1.com/rsc3.t");
		PageInternet p4("http://site1.com/rsc4.t");
		PageInternet p5("http://site1.com/rsc5.t");
		p1.SetEstIsole(false);
		p2.SetEstIsole(false);
		p3.SetEstIsole(false);
		p4.SetEstIsole(false);
		p5.SetEstIsole(false);
		g[p1];
		g[p2];
		g[p3];
		g[p4];
		g[p5];
		g[p1].push_back( ArcRequete( p2, 1 ) );
		g[p1].push_back( ArcRequete( p3, 3 ) );
		g[p1].push_back( ArcRequete( p4, 7 ) );
		g[p4].push_back( ArcRequete( p5, 9 ) );
		g[p3].push_back( ArcRequete( p5, 2 ) );
		g[p2].push_back( ArcRequete( p1, 5 ) );
		g.ExportFormatGraphViz("testsGraphe/out5.dot");
	}
	    //Test 6 Graphe quelconque
	{
		GrapheRequetes g;
		PageInternet p1("http://site1.com/home.html");
		PageInternet p2("http://site1.com/rsc1.t");
		PageInternet p3("http://site1.com/rsc2.t");
		PageInternet p4("http://site2.com/more.html");
		PageInternet p5("http://site2.com/rsc1.t");
		p1.SetEstIsole(false);
		p2.SetEstIsole(true);
		p3.SetEstIsole(false);
		p4.SetEstIsole(false);
		p5.SetEstIsole(true);
		g[p1];
		g[p2];
		g[p3];
		g[p4];
		g[p5];
		g[p1].push_back( ArcRequete( p4, 1 ) );
		g[p2].push_back( ArcRequete( p4, 1 ) );
		g[p2].push_back( ArcRequete( p1, 1 ) );
		g[p3].push_back( ArcRequete( p1, 1 ) );
        g[p5].push_back( ArcRequete( p4, 1 ) );
		g.ExportFormatGraphViz("testsGraphe/out6.dot");
	}
	    //Test 7 fichier d'export non dot
	{
		GrapheRequetes g;
		PageInternet p1("http://site1.com/home.html");
		PageInternet p2("http://site1.com/rsc1.t");
		PageInternet p3("http://site1.com/rsc2.t");
		PageInternet p4("http://site2.com/more.html");
		PageInternet p5("http://site2.com/rsc1.t");
		p1.SetEstIsole(false);
		p2.SetEstIsole(true);
		p3.SetEstIsole(false);
		p4.SetEstIsole(false);
		p5.SetEstIsole(true);
		g[p1];
		g[p2];
		g[p3];
		g[p4];
		g[p5];
		g[p1].push_back( ArcRequete( p4, 1 ) );
		g[p2].push_back( ArcRequete( p4, 1 ) );
		g[p2].push_back( ArcRequete( p1, 1 ) );
		g[p3].push_back( ArcRequete( p1, 1 ) );
        g[p5].push_back( ArcRequete( p4, 1 ) );
		g.ExportFormatGraphViz("testsGraphe/out7.txt");
	}
	//Test 8 page Tronquee apres 30 caracteres
	{
		GrapheRequetes g;
		PageInternet p1("http://site1.com/intermededecaracteresincroyablementlongafindeverifiersilatroncatureestbieneffectuee/rsc.t");
		PageInternet p2("http://site1.com/rsc2.t");
		p1.SetEstIsole(false);
		p2.SetEstIsole(true);
		g[p1];
		g[p2];
		g[p1].push_back( ArcRequete( p2, 1 ) );
		g[p2].push_back( ArcRequete( p1, 5 ) );
		g.ExportFormatGraphViz("testsGraphe/out8.dot");
	}
}


