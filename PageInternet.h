/*************************************************************************
                           PageInternet -  description
                             -------------------
    d�but                : 23/11/2015
    copyright            : (C) 2015 par Pericas-Moya & Belletier
*************************************************************************/

//---------- Interface de la classe <PageInternet> (fichier PageInternet.h) ------
#if ! defined ( PAGEINTERNET_H )
#define PAGEINTERNET_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>

//------------------------------------------------------------- Constantes
const std::string IMAGE = ".png.gif.jpeg.jpg.bmp.tiff.ico";		// Pages de type image
const std::string SCRIPT = ".js.css";							// Pages de type script css ou javascript

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <PageInternet>
//
//
//------------------------------------------------------------------------

class PageInternet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste de param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    std::string GetRacine ( ) const;
    // Mode d'emploi :
    //
    // Contrat :
    // Doit renvoyer "-" si l'url est "-"
    // Doit renvoyer "" si l'url est locale

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
    // Mode d'emploi : Renvoie la chaine pour output l'entierete de l'url dans un graphviz
    //
    // Contrat :
    //

    std::string GetOutputExt ( ) const;
    // Mode d'emploi : Renvoie la chaine pour output l'extension de l'url dans un graphviz
    //
    // Contrat :
    //

	std::string GetUrl ( ) const { return url; }

    bool GetEstIsole( ) const { return estIsole; }
    //getter simple
    void SetEstIsole( bool value ) { estIsole = value; }

//------------------------------------------------- Surcharge d'op�rateurs
    PageInternet& operator = ( const PageInternet& unePageInternet );
    // Mode d'emploi : donne une url similaire mais garde la diff�rence d'identifiants
    //
    // Contrat :
    //
	bool operator< ( const PageInternet& unePageInternet ) const;
	// Mode d'emploi :
    //
    // Contrat :
    //

    bool operator== ( const PageInternet& unePageInternet ) const;
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
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s
    std::string url;
    bool estIsole;

private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <PageInternet>

#endif // PAGEINTERNET_H
