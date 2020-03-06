#ifndef AFFICHAGECOMBI_H
#define AFFICHAGECOMBI_H

#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QBoxLayout>
#include "combinaison.h"
#include <vector>
#include "graphicpion.h"

class AffichageCombi
{
    public:
    AffichageCombi(int i);
    QHBoxLayout *GetLayout();
    void remplirLigne(Combinaison *proposition, int blanche, int noire);
    void clear();

    private:
    QHBoxLayout *layout;
    QLabel *tour;
    std::vector<GraphicPion*> pions;

    QLCDNumber *blanc;
    QLCDNumber *noir;
};

#endif // AFFICHAGECOMBI_H
