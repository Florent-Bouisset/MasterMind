#ifndef COMBINAISON_H
#define COMBINAISON_H
#include <vector>
#include "pion.h"

class Combinaison
{
    public:
        Combinaison();
        Combinaison(std::vector<int> sqnce);
        int getTailleSequence();
        std::vector<Pion> getSequence();
        void createVectorSequence();
        void randomizeSequence();
        bool isEqual(Combinaison *b);

        int compteCouleur(int numCouleur);
        int CompteCouleurBienPlace(int numCouleur, Combinaison *b);
        int compteBienPlace(Combinaison *b);
        int compteMalPlace(Combinaison *b);


    private:
        int tailleSequence;
        std::vector<Pion> sequence;


};

#endif // COMBINAISON_H
