/*************************************************************************
                           PageInternet  -  description
                             -------------------
    d�but                : 23/11/2015
    copyright            : (C) 2015 par Pericas-Moya & Belletier
*************************************************************************/

//---------- R�alisation de la classe <PageInternet> (fichier PageInternet.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "PageInternet.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies
//----------------------------------------------------- M�thodes publiques
// type PageInternet::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

std::string PageInternet::GetRacine() const
//Algorithme : recherche du / de s�paration dans la chaine
{
    std::string racine;
    size_t tampon;//traite le cas o� on a une adresse compl�te
    if (adresse == "-")//traitement du cas limite
    {
        return "-";
    }
    tampon = adresse.find("/");
    if (tampon != string::npos)
    {

        if(tampon < adresse.size() -2)//on evite la sortie de tableau au adresse suivant
        {
            if( adresse[tampon+1]=='/' )//on evite de s'arreter au // de http://
            {
                tampon = adresse.find("/",tampon+2);
                racine = adresse.substr(0,tampon);
            }
            else
            {
                racine = adresse.substr(0,tampon);
            }
        }
        else
        {
            racine = adresse.substr(0,tampon);
        }
    }
    else
    {
        racine = adresse;
    }
    return racine;
}

std::string PageInternet::GetOutputComplet() const
//Algorithme : recherche du // pour l'echapper+ echappage des "
{
    size_t tampon = adresse.find("/");
    std::string adresseEchappee = adresse;
    //Recherche du //
    if (tampon != string::npos)
    {

        if(tampon < adresse.size() -1)//on evite la sortie de tableau au adresse suivant
        {
            if( adresse[tampon+1]=='/' )//on verifie que c'est // et pas / (� priori il n'y en aura qu'un)
            {
                adresseEchappee = adresse.substr(0,tampon) + "\\" + adresse[tampon+1];//On insere un \ pour echapper le deuxieme /
            }
            else
            {
                adresseEchappee = adresse;
            }
        }
        else
        {
            adresseEchappee = adresse;
        }
    }
    //retour
    return "\"" + adresseEchappee + "\"";
}

std::string PageInternet::GetOutputExt() const
//Algorithme : echappage des "
{
    return "\"" + GetExtension() + "\"";
}

std::string PageInternet::GetExtension() const
//Algorithme : recherche du / de s�paration dans la chaine
{
    std::string extension;
    size_t tampon;//traite le cas o� on a une adresse compl�te
    if (adresse == "-")//traitement du cas limite
    {
        return "";
    }
    tampon = adresse.find("/");
    if (tampon != string::npos)
    {

        if(tampon < adresse.size() -2)//on evite la sortie de tableau au adresse suivant
        {
            if( adresse[tampon+1]=='/' )//on evite de s'arreter au // de http://
            {
                tampon = adresse.find("/",tampon+2);
                if ( tampon != string::npos)
                {
                    extension = adresse.substr(tampon);
                }
                else
                {
                    extension = "";
                }
            }
            else
            {
                extension = adresse.substr(tampon);
            }
        }
        else
        {
            extension = adresse.substr(tampon);
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
	return "";
}

//------------------------------------------------- Surcharge d'op�rateurs
PageInternet & PageInternet::operator = ( const PageInternet & unePageInternet )
// Algorithme : egalit� attributs � attributs
{
    adresse = unePageInternet.adresse;
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
PageInternet::PageInternet ( const PageInternet & unePageInternet ) :
				adresse(unePageInternet.adresse)
// Algorithme :
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <PageInternet>" << endl;
#endif
} //----- Fin de PageInternet (constructeur de copie)


PageInternet::PageInternet ( ) : adresse("-")
// Algorithme : la page internet de base est celle de l'acc�s direct
{
#ifdef MAP
    cout << "Appel au constructeur de <PageInternet>" << endl;
#endif

} //----- Fin de PageInternet


PageInternet::~PageInternet ( )
// Algorithme : rien de particulier � faire
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PageInternet>" << endl;
#endif
} //----- Fin de ~PageInternet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
