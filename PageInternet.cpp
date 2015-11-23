/*************************************************************************
                           PageInternet  -  description
                             -------------------
    début                : 23/11/2015
    copyright            : (C) 2015 par Pericas-Moya & Belletier
*************************************************************************/

//---------- Réalisation de la classe <PageInternet> (fichier PageInternet.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "PageInternet.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies
//----------------------------------------------------- Méthodes publiques
// type PageInternet::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

std::string PageInternet::GetRacine()
//Algorithme : recherche du / de séparation dans la chaine
{
    std::string racine;
    size_t tampon;//traite le cas où on a une adresse complète
    if (this.adresse == "-")//traitement du cas limite
    {
        return "-";
    }
    tampon = this.adresse.find("/");
    if (tampon != string::npos)
    {

        if(tampon < this.adresse.size() -2)//on evite la sortie de tableau au this.adresse suivant
        {
            if( this.adresse[tampon+1]=='/' )//on evite de s'arreter au // de http://
            {
                tampon = this.adresse.find("/",tampon+2);
                racine = this.adresse.substr(0,tampon);
            }
            else
            {
                racine = this.adresse.substr(0,tampon);
            }
        }
        else
        {
            racine = this.adresse.substr(0,tampon);
        }
    }
    else
    {
        racine = this.adresse;
    }
    return racine;
}

std::string PageInternet::GetExtension()
//Algorithme : recherche du / de séparation dans la chaine
{
    std::string extension;
    size_t tampon;//traite le cas où on a une adresse complète
    if (this.adresse == "-")//traitement du cas limite
    {
        return "";
    }
    tampon = this.adresse.find("/");
    if (tampon != string::npos)
    {

        if(tampon < this.adresse.size() -2)//on evite la sortie de tableau au this.adresse suivant
        {
            if( this.adresse[tampon+1]=='/' )//on evite de s'arreter au // de http://
            {
                tampon = this.adresse.find("/",tampon+2);
                if ( tampon != string::npos)
                {
                    extension = this.adresse.substr(tampon);
                }
                else
                {
                    extension = "";
                }
            }
            else
            {
                extension = this.adresse.substr(tampon);
            }
        }
        else
        {
            extension = this.adresse.substr(tampon);
        }
    }
    else
    {
        extension = "";
    }
    return extension;
}

//------------------------------------------------- Surcharge d'opérateurs
PageInternet & PageInternet::operator = ( const PageInternet & unPageInternet )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
PageInternet::PageInternet ( const PageInternet & unPageInternet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <PageInternet>" << endl;
#endif
} //----- Fin de PageInternet (constructeur de copie)


PageInternet::PageInternet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PageInternet>" << endl;
#endif
} //----- Fin de PageInternet


PageInternet::~PageInternet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PageInternet>" << endl;
#endif
} //----- Fin de ~PageInternet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
