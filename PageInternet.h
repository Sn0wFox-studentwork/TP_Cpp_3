/*************************************************************************
                           PageInternet -  description
                             -------------------
    d�but                : 23/11/2015
    copyright            : (C) 2015 par Pericas-Moya & Belletier
*************************************************************************/

//---------- Interface de la classe <${file_base}> (fichier ${file_name}) ------
#if ! defined ( PAGEINTERNET_H )
#define PAGEINTERNET_H

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <${file_base}>
//
//
//------------------------------------------------------------------------ 

class PageInternet: 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste de param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'op�rateurs
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
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s

private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <${file_base}>

#endif // PAGEINTERNET_H
