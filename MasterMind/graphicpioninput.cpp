#include "graphicpioninput.h"
#include <QPushButton>
#include <QPixmap>

GraphicPionInput::GraphicPionInput() : QPushButton()
{
    codeCouleur = -1;
    couleurMax = 6; // nombre de couleurs de 0 jusqu'a 5 donc 6 couleurs
    updateColor();
    connect(this, SIGNAL(released()),this, SLOT(incrementCodeCouleur()));

}

void GraphicPionInput::updateColor(){
    QString path = "";
    switch(codeCouleur){

        case -1:
            path = "img/beige.png";
            break;
        case 0:
            path = "img/vert.png";
            break;
        case 1:
            path = "img/jaune.png";
            break;
        case 2:
            path = "img/rouge.png";
            break;
        case 3:
            path = "img/bleufonce.png";
            break;
        case 4:
            path = "img/orange.png";
            break;
        case 5:
            path = "img/fushia.png";
            break;

        default:
            path = "img/beige.png";
            break;
    }

    QPixmap img = QPixmap(path);
    QIcon buttonIcon(img);
    this->setIcon(buttonIcon);
    this->setIconSize(img.rect().size());
}

void GraphicPionInput::setCodeCouleur(int code)
{
    codeCouleur = code;
    updateColor();
}

/**
 * @brief GraphicPionInput::incrementCodeCouleur
 * incremente la couleur du pion, si couleur max atteinte on revient on début
 */
void GraphicPionInput::incrementCodeCouleur(){
    codeCouleur++;
    if(codeCouleur == couleurMax){
        codeCouleur = 0;
    }
    updateColor();
}

int GraphicPionInput::getCodeCouleur()
{
    return codeCouleur;
}
