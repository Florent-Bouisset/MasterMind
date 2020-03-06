/******************************************************************************
Programme:
Auteur: Florent Bouisset
Date de creation:
Date de modification
version:
*******************************************************************************
Commentaires:
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "pion.h"

using namespace std;


Pion::Pion()
{
    nbCouleurPossible = 6;
    randomizePion();
}

Pion::Pion(int numCouleur)
{
    nbCouleurPossible = 6;
    codeCouleur = numCouleur;

}

/**
    Rend aléatoire la couleur d'un pion
*/
void Pion::randomizePion()
{
    codeCouleur = rand() % nbCouleurPossible;
}



/**
    Renvoie true si les deux pions sont de meme couleurs
*/
bool Pion::isEqual(Pion b)
{
    return codeCouleur == b.codeCouleur;

}

/**
    Renvoie le code couleur du pion
*/
int Pion::getCodeCouleur()
{
    return codeCouleur;
}

/**
    Renvoie le nombre de couleur possible pour un pion
*/
int Pion::getNbCouleurPossible()
{
    return nbCouleurPossible;
}

