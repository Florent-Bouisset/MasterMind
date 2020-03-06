#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>
#include <QMessageBox>
#include <QWidget>
#include "mafenetre.h"
#include "historique.h"
#include "saisicombinaison.h"
#include "entete.h"
#include "combinaison.h"
#include "partie.h"



MaFenetre::MaFenetre() : QWidget()
{
    QVBoxLayout *layout = new QVBoxLayout();

    m_titre = new QLabel("<center>MasterMind</center>");
    QFont *fontTitle = new QFont();
    fontTitle->setPointSize(16);
    m_titre->setFont(*fontTitle);

    boutonValider = new QPushButton("Valider la combinaison");
    QObject::connect(boutonValider, SIGNAL(clicked()), this, SLOT(jouerUnTour()));

    Entete *entete = new Entete();
    historique = new Historique();
    saisi = new SaisiCombinaison();
    partie = new Partie();

    layout->addWidget(m_titre);
    layout->addLayout(entete->getLayout());
    layout->addLayout(historique->getLayout());
    layout->addLayout(saisi->getLayout());
    layout->addWidget(boutonValider);

    // rends la fenetre non déformable  et désactive les fleches pour agrandir la fenetre au survol du curseur
    this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    this->setLayout(layout);
}

void MaFenetre::jouerUnTour()
{
    //recupere les entrées
    Combinaison *proposition = saisi->getCombinaison();
    //Combinaison *proposition = new Combinaison();

    //compare avec la solution
    int bienPlace = partie->getSolution()->compteBienPlace(proposition);
    int malPlace = partie->getSolution()->compteMalPlace(proposition);

    //rempli l'historique
    historique->getTour(partie->getNumCoup())->remplirLigne(proposition, malPlace ,bienPlace);

    partie->incrementeNumCoup();
    //verifie si partie est gagné
    partie->checkProposition(proposition);
    if(partie->isGameOver()){
        if(partie->getResolu()){
            affichePopUpVictoire();
        }
        else{
            affichePopUpDefaite();
        }
    }
}

void MaFenetre::affichePopUpVictoire()
{
    QString numero = QString::number(partie->getNumCoup());
    QMessageBox::information(this,"Fin de la partie", "Bravo tu as gagné la partie en " + numero + " coups !" );
    newGame();
}

void MaFenetre::affichePopUpDefaite()
{
    QMessageBox::information(this,"Fin de la partie", "Dommage tu as perdu ... ");
    newGame();
}

void MaFenetre::clear()
{
    historique->clear();
    saisi->clear();
}

void MaFenetre::newGame()
{
    clear();
    delete partie;
    partie = new Partie();

}







