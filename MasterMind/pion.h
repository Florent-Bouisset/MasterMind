#ifndef PIONCOULEUR_H
#define PIONCOULEUR_H

class Pion
{
    public:

        Pion(); // constructeur
        Pion(int numCouleur);
        int getCodeCouleur();
        int getNbCouleurPossible();
        bool isEqual(Pion pionB);
        void randomizePion();


    private:

        int codeCouleur;
        int nbCouleurPossible;
};

#endif // PIONCOULEUR_H
