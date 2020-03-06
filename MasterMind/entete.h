#ifndef ENTETE_H
#define ENTETE_H
#include <QHBoxLayout>

class Entete
{
    public:
    Entete();
    QHBoxLayout *getLayout();


    private:
    QHBoxLayout *layout;
};

#endif // ENTETE_H
