#include <QBoxLayout>
#include <QString>
#include <QLCDNumber>
#include <vector>
#include "graphicpion.h"
#include "combinaison.h"
#include "affichagecombi.h"

AffichageCombi::AffichageCombi(int i)
{
    int taille = 4;
    layout = new QHBoxLayout();
    QString numero = QString::number(i+1);
    tour = new QLabel("Tour " + numero);

    for (int i=0; i < taille; i++){
        pions.push_back(new GraphicPion());
    }

    QLabel *espace = new QLabel();
    blanc = new QLCDNumber();
    noir = new QLCDNumber();

    layout->addWidget(tour);
    for(int i=0; i < taille; i++){
        layout->addWidget(pions.at(i));
    }
    layout->addWidget(espace);
    layout->addWidget(blanc);
    layout->addWidget(noir);
}

QHBoxLayout *AffichageCombi::GetLayout()
{
    return this->layout;
}

void AffichageCombi::remplirLigne(Combinaison *proposition, int blanche, int noire)
{
    int code;
    for(int i=0; i < 4 ;i++){
        code = proposition->getSequence().at(i).getCodeCouleur();
        pions.at(i)->assignColor(code);
    }

    blanc->display(blanche);
    noir->display(noire);
}

void AffichageCombi::clear()
{
    for(int i=0; i<4; i++){
        pions.at(i)->assignColor(-1);
    }
    noir->display(0);
    blanc->display(0);
}
