/*************************************************************************
                           PageInternet -  description
                             -------------------
    début                : 23/11/2015
    copyright            : (C) 2015 par Pericas-Moya & Belletier
*************************************************************************/

//---------- Interface de la classe <${file_base}> (fichier ${file_name}) ------
#if ! defined ( PAGEINTERNET_H )
#define PAGEINTERNET_H
#include <string>
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <${file_base}>
//
//
//------------------------------------------------------------------------

class PageInternet:
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    std::string GetRacine() const;
    // Mode d'emploi :
    //
    // Contrat :
    // Doit renvoyer "-" si l'adresse est "-"
    // Doit renvoyer "" si l'adresse est locale

	std::string GetExtension() const;
	// Mode d'emploi :
    //
    // Contrat :
    //

	std::string GetType() const;
	// Mode d'emploi :
    //
    // Contrat :
    //

    std::string GetOutputComplet() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    std::string GetOutputComplet() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    PageInternet& operator = ( const PageInternet& unPageInternet);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    PageInternet( const PageInternet& unPageInternet);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    PageInternet( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~PageInternet( );
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
    string adresse;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <${file_base}>

#endif // PAGEINTERNET_H
