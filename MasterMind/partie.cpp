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
#include <time.h>
#include "partie.h"
#include "combinaison.h"


using namespace std;

Partie::Partie()
{
    resolu = false;
    nbCoup = 8;
    numCoup = 0;
    solution = new Combinaison();
    solution->randomizeSequence();

}





/**
    Verifie si la proposition est identique avec la solution,
    indique la partie comme résolu si identique
*/
void Partie::checkProposition(Combinaison* proposition)
{
    if(solution->isEqual(proposition)){
        resolu = true;
    }
}

Combinaison* Partie::getSolution(){
    return solution;
}

int Partie::getNumCoup(){
    return numCoup;
}

void Partie::incrementeNumCoup(){
    numCoup++;
}

bool Partie::isGameOver()
{
    bool fini = false;
    if(resolu == true){
        fini = true;
    }
    else {
        if(numCoup == nbCoup){ //si le nombre de coup max est joué
            fini = true;
        }
    }
    return fini;
}

bool Partie::getResolu()
{
    return resolu;
}

