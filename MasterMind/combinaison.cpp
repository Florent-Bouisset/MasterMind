/******************************************************************************
Programme:
Auteur: Florent Bouisset
Date de creation:
Date de modification
version:
*******************************************************************************
Commentaires:
******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <time.h>
#include <vector>
#include "combinaison.h"
#include "pion.h"

using namespace std;

Combinaison::Combinaison()
{
    tailleSequence = 4;
    createVectorSequence();
}

Combinaison::Combinaison(std::vector<int> sqnce)
{
    tailleSequence = sqnce.size();
    for (int i = 0 ; i < tailleSequence; i++){
        sequence.push_back(Pion(sqnce.at(i)));
    }
}

/**
    ajuste la taille du vecteur pour pouvoir y mettre les pions
*/
void Combinaison::createVectorSequence()
{
    for(int i = 0; i < tailleSequence; i++){
            sequence.push_back(Pion());
        }
}

/**
    Modifie aléatoirement la séquence
    Utile pour jouer contre l'ordinateur
*/
void Combinaison::randomizeSequence()
{
    for(int i = 0; i < tailleSequence; i++){
        sequence.at(i).randomizePion();
    }
}


/**
    Compte le nombre de boules bien placés avec la combinaison b
    Equivalent des boules noires au mastermind

*/
int Combinaison::compteBienPlace(Combinaison *b)
{
    int compteur = 0;
    int nb = sequence.at(0).getNbCouleurPossible();
    for(int i = 0; i < nb; i++){
        compteur = compteur + CompteCouleurBienPlace(i,b);
    }
    return compteur;
}

/**
    Compte le nombre de boules mal placés avec la combinaison b
    Equivalent des boules blanches au mastermind
*/
int Combinaison::compteMalPlace(Combinaison *b)
{
    int compteur = 0;
    int couleur = 0;
    int nbCouleur = sequence.at(0).getNbCouleurPossible();
    for(int i = 0; i < nbCouleur ; i++){
        couleur = min(compteCouleur(i),b->compteCouleur(i)) - CompteCouleurBienPlace(i,b);
        compteur = compteur + couleur;
    }
    return compteur;
}



/**
    Compte le nombre de fois qu'une couleur spécifié est présente dans une combinaison
    La couleur est spécifié par le numCouleur
    Ex: la combinaison (rouge, bleu, vert, rouge) renvoie 2 pour compteCouleur(numeroRouge)
*/
int Combinaison::compteCouleur(int numCouleur)
{
    int compteur = 0;
    for(int i = 0; i < tailleSequence; i++){
        if(sequence.at(i).getCodeCouleur() == numCouleur){
            compteur++;
        }
    }
    return compteur;
}

/**
    Compte le nombre de fois qu'une couleur spécifié est aux meme endroit dans les deux combinaisons
    La couleur est spécifié par le numCouleur
    Ex:(rouge,vert,jaune) et (rouge,jaune,vert) renvoie 1 si la couleur spécifié est le rouge
*/
int Combinaison::CompteCouleurBienPlace(int numCouleur, Combinaison *b)
{
    int compteur = 0;
    for(int i = 0; i < tailleSequence; i++){
        if((sequence.at(i).getCodeCouleur() == numCouleur)&& (sequence.at(i).isEqual(b->sequence.at(i)))){
            compteur++;
        }
    }
    return compteur;
}

bool Combinaison::isEqual(Combinaison *b)
{
    bool isEqual = false;
    int bouleNoires = compteBienPlace(b);
    if(bouleNoires == tailleSequence){
        isEqual = true;
    }
    return isEqual;
}

std::vector<Pion> Combinaison::getSequence()
{
    return sequence;
}
