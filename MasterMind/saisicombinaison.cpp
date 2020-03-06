#include "saisicombinaison.h"
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "combinaison.h"
#include <QObject>
#include <vector>
#include "graphicpioninput.h"

SaisiCombinaison::SaisiCombinaison()
{
    int taille = 4;
    layout = new QHBoxLayout();

    for(int i = 0; i< taille; i++){
        pions.push_back(new GraphicPionInput());
    }

    QLabel *blank = new QLabel("            ");

    //Ajoute tous les widgets au layout
    layout->addWidget(blank);

    for(int i=0; i < taille; i++){
        layout->addWidget(pions.at(i));
    }
    layout->addWidget(blank);
}

QHBoxLayout *SaisiCombinaison::getLayout()
{
    return layout;
}

Combinaison *SaisiCombinaison::getCombinaison()
{
    int taille = 4;

    std::vector<int> sqnce;

    for(int i = 0; i < taille; i++){
        sqnce.push_back(pions.at(i)->getCodeCouleur());
    }

    Combinaison *combi = new Combinaison(sqnce);
    return combi;
}


void SaisiCombinaison::clear()
{
    for(int i=0; i<4; i++){
        pions.at(i)->setCodeCouleur(-1);
    }
}
























