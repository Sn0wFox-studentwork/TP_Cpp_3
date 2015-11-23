#pragma once
#include <string>
#include "PageInternet.h"

class Requete
{
public:
	Requete();
	virtual ~Requete();
	PageInternet GetReferenceur() const;
	PageInternet GetCible() const;
	bool operator<(const Requete& autreRequete) const;
	// Base sur Ordre lexicographique (< pour les string) : 1) referenceur 2) cible
	bool operator==(const Requete& autreRequete) const;
	// Base sur Ordre lexicographique (< pour les string) : 1) referenceur 2) cible
};

