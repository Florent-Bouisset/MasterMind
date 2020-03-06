#include <QApplication>
#include "mafenetre.h"


int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    srand(time(NULL));

    MaFenetre fenetre;
    fenetre.show();

    return app.exec();

}
