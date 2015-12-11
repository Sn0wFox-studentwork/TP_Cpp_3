#pragma once

#include <algorithm>
#include <list>
#include "Application.h"
#include "PageInternet.h"

void Tests ( );
void TestFlags ( );
void TestFind ( );
void TestTri ( );
void TestGraph ( );
void TestFichier ( );
void TestPrintResultats ( );
void TestGrosFichierGraph ( );
void TestPageInternetGets ( );
void TestPageInternetOp ( );
void TestPageInternet ( );
void TestGrapheExport ( );

typedef std::pair<PageInternet, int> AccesPage;
typedef std::list<AccesPage> MeilleuresPages;
typedef MeilleuresPages::iterator IterateurMeilleuresPages;

struct ComparaisonAccesPages
{
	bool operator() ( const AccesPage& ap1, const AccesPage& ap2 ) const
	{
		return ap1.second > ap2.second;
	}
};

