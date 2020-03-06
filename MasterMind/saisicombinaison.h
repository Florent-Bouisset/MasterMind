#ifndef SAISICOMBINAISON_H
#define SAISICOMBINAISON_H
#include <QHBoxLayout>
#include <QObject>
#include <vector>
#include "combinaison.h"
#include "graphicpioninput.h"

class SaisiCombinaison : QObject
{
    public:
    SaisiCombinaison();
    QHBoxLayout *getLayout();
    Combinaison *getCombinaison();
    void clear();

    private:
    QHBoxLayout *layout;
    std::vector<GraphicPionInput*> pions;

};

#endif // SAISICOMBINAISON_H
