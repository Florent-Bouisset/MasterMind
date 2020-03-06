#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include "affichagecombi.h"
#include <QVBoxLayout>
#include <vector>

class Historique
{
    public:
    Historique();
    QVBoxLayout *getLayout();
    AffichageCombi *getTour(int i);
    void clear();

    private:
    QVBoxLayout *layout;
    std::vector<AffichageCombi*> tours;

};



#endif // HISTORIQUE_H
