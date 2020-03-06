#include "historique.h"
#include "affichagecombi.h"
#include <QVBoxLayout>

Historique::Historique()
{
        layout = new QVBoxLayout;
        int taille = 8;
        for(int i = 0; i < taille ; i ++){
            tours.push_back(new AffichageCombi(i));
            layout->addLayout(tours.at(i)->GetLayout());
        }

}


QVBoxLayout *Historique::getLayout()
{
    return layout;
}

AffichageCombi *Historique::getTour(int i)
{
    return tours.at(i);
}

void Historique::clear()
{
    for(int i = 0; i<8; i++){
        tours.at(i)->clear();
    }
}
