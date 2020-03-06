#include "entete.h"
#include <QLabel>
#include <QHBoxLayout>


Entete::Entete()
{

    layout = new QHBoxLayout();
    layout->insertSpacing(0,200);

    QLabel *blanche = new QLabel("<center>Blanche</center>");
    QLabel *noire = new QLabel("<center>Noire</center>");

    layout->addWidget(blanche);
    layout->addWidget(noire);

}

QHBoxLayout *Entete::getLayout()
{
    return layout;
}
