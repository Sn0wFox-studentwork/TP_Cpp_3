/*************************************************************************
                           PageInternet -  description
                             -------------------
    début                : 23/11/2015
    copyright            : (C) 2015 par Pericas-Moya & Belletier
*************************************************************************/

//---------- Interface de la classe <PageInternet> (fichier PageInternet.h) ------
#if ! defined ( PAGEINTERNET_H )
#define PAGEINTERNET_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------- Constantes
const std::string IMAGE = ".png.gif.jpeg.jpg.bmp.tiff";		// Pages de type image
const std::string SCRIPT = ".js.css";						// Pages de type script css ou javascript

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <PageInternet>
//
//
//------------------------------------------------------------------------

class PageInternet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    std::string GetRacine ( ) const;
    // Mode d'emploi :
    //
    // Contrat :
    // Doit renvoyer "-" si l'adresse est "-"
    // Doit renvoyer "" si l'adresse est locale

	std::string GetExtension ( ) const;
	// Mode d'emploi :
    //
    // Contrat :
    //

	std::string GetType ( ) const;
	// Mode d'emploi :	Retourne le type de la page (ce qui se situe apres le .).
    //
    // Contrat :
    //

    std::string GetOutputComplet ( ) const;
    // Mode d'emploi : Renvoie la chaine pour output l'entierete de l'adresse dans un graphviz
    //
    // Contrat :
    //

    std::string GetOutputExt ( ) const;
    // Mode d'emploi : Renvoie la chaine pour output l'extension de l'adresse dans un graphviz
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    PageInternet& operator = ( const PageInternet& unePageInternet );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    PageInternet( const PageInternet& unePageInternet );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    PageInternet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

	PageInternet ( const std::string& url );

    virtual ~PageInternet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
    std::string adresse;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <PageInternet>

#endif // PAGEINTERNET_H
