#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "historique.h"
#include "saisicombinaison.h"
#include "partie.h"

class MaFenetre : public QWidget
{
    Q_OBJECT
    public:
    MaFenetre();
    void affichePopUpVictoire();
    void affichePopUpDefaite();
    void clear();
    void newGame();

    public slots:
    void jouerUnTour();

    private:
    QPushButton *boutonValider;
    QLabel *m_titre;
    Partie *partie;
    Historique *historique;
    SaisiCombinaison *saisi;
};

#endif // MAFENETRE_H
