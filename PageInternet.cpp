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

std::string PageInternet::GetRacine() const
//Algorithme : recherche du / de séparation dans la chaine
{
    std::string racine;
    size_t tampon;//traite le cas où on a une url complète
    if (url == "-")//traitement du cas limite
    {
        return "-";
    }
    tampon = url.find("/");
    if (tampon != string::npos)
    {

        if(tampon < url.size() -2)//on evite la sortie de tableau au test suivant
        {
            if( url[tampon+1]=='/' )//on evite de s'arreter au // de http://
            {
                if(url.substr(tampon+2).find("/") != string::npos)
                {
                    tampon = tampon + 2 + url.substr(tampon+2).find("/");
                    racine = url.substr(0,tampon);
                }
                else
                {
                    racine = url;
                }

            }
            else
            {
                racine = url.substr(0,tampon);
            }
        }
        else
        {
            racine = url.substr(0,tampon);
        }
    }
    else
    {
        racine = url;
    }
    return racine;
}

std::string PageInternet::GetOutputComplet() const
//Algorithme : recherche du // pour l'echapper+ echappage des "
{
    size_t tampon = url.find("/");
    std::string urlEchappee = url;
    //Recherche du //
    if (tampon != string::npos)
    {

        if(tampon < url.size() -1)//on evite la sortie de tableau au url suivant
        {
            if( url[tampon+1]=='/' )//on verifie que c'est // et pas / (à priori il n'y en aura qu'un)
            {
                urlEchappee = url.substr(0,tampon+1) + "\\" + url.substr(tampon+1);//On insere un \ pour echapper le deuxieme /
            }
            else
            {
                urlEchappee = url;
            }
        }
        else
        {
            urlEchappee = url;
        }
    }
    //retour
    return "\"" + urlEchappee + "\"";
}

std::string PageInternet::GetOutputExt() const
//Algorithme : echappage des "
{
    return "\"" + GetExtension() + "\"";
}

std::string PageInternet::GetExtension() const
//Algorithme : recherche du / de séparation dans la chaine
{
    std::string extension;
    size_t tampon;//traite le cas où on a une url complète
    if (url == "-")//traitement du cas limite
    {
        return "";
    }
    tampon = url.find("/");
    if (tampon != string::npos)
    {

        if(tampon < url.size() -2)//on evite la sortie de tableau au url suivant
        {
            if( url[tampon+1]=='/' )//on evite de s'arreter au // de http://
            {
                if ( url.substr(tampon+2).find("/") != string::npos)
                {
                    tampon = tampon + 2 + url.substr(tampon+2).find("/");
                    extension = url.substr(tampon);
                }
                else
                {
                    extension = "";
                }
            }
            else
            {
                extension = url.substr(tampon);
            }
        }
        else
        {
            extension = url.substr(tampon);
        }
    }
    else
    {
        extension = "";
    }
    return extension;
}

string PageInternet::GetType() const
{
	size_t tampon;//recupere l'url du dernier point
	tampon = url.rfind(".");
	if ( tampon != string::npos )//dans le cas où il y a un type de fichier défini
	{
		return url.substr(tampon);
	}
	return "";
}

//------------------------------------------------- Surcharge d'opérateurs
PageInternet & PageInternet::operator= ( const PageInternet & unePageInternet )
// Algorithme :	Si on n'est pas en train de faire unePageInternet = unePageInternet,
//				on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unePageInternet.
{
	if ( this != &unePageInternet )
	{
		url = unePageInternet.url;
		estIsole = unePageInternet.estIsole;
	}
	return *this;

} //----- Fin de operator =

bool PageInternet::operator< ( const PageInternet& unePageInternet ) const
//Algorithme : comparaison d'url
{
	return url < unePageInternet.url;

} // Fin de operator <

bool PageInternet::operator== ( const PageInternet& unePageInternet ) const
{
	return url == unePageInternet.url;
} // Fin de operator ==

//-------------------------------------------- Constructeurs - destructeur
PageInternet::PageInternet ( const PageInternet & unePageInternet ) :
				url( unePageInternet.url ),
				estIsole( unePageInternet.estIsole )
// Algorithme :
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <PageInternet>" << endl;
#endif
} //----- Fin de PageInternet (constructeur de copie)


PageInternet::PageInternet ( ) : url("-"), estIsole(true)
// Algorithme : la page internet de base est celle de l'accès direct
{
#ifdef MAP
    cout << "Appel au constructeur de <PageInternet>" << endl;
#endif

}	//----- Fin de PageInternet


PageInternet::PageInternet( const std::string& url ) : url( url ), estIsole(true)
// Algorithme :
{
#ifdef MAP
    cout << "Appel au constructeur par url de <PageInternet>" << endl;
#endif
}	//----- Fin de PageInternet

PageInternet::~PageInternet ( )
// Algorithme : rien de particulier à faire
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PageInternet>" << endl;
#endif
} //----- Fin de ~PageInternet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
