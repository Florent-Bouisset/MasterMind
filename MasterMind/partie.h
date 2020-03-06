#ifndef PARTIE_H
#define PARTIE_H
#include <vector>
#include "combinaison.h"

class Partie
{
    public:
        Partie();
        void checkProposition(Combinaison* proposition);
        Combinaison *getSolution();
        int getNumCoup();
        void incrementeNumCoup();
        bool isGameOver();
        bool getResolu();

    private:
        bool resolu;
        int nbCoup;
        int numCoup; //numero du coup en cours
        Combinaison* solution;
        std::vector<Combinaison*> historiqueCoup;

};

#endif // PARTIE_H
