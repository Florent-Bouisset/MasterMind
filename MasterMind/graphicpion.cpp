#include "graphicpion.h"
#include <QLabel>
#include <QPixmap>
#include <QString>

/**
 * @brief GraphicPion::GraphicPion
 * cette classe permet de creer un widget qui ressemble a un pion de couleur d'une combinaison de mastermind
 * @param code, correspond a une couleur particuliere
 */



GraphicPion::GraphicPion(int code) : QLabel()
{
    this->assignColor(code);
}

GraphicPion::GraphicPion() : GraphicPion(-1)
{}

void GraphicPion::assignColor(int code)
{
    this->codeCouleur = code;
    this->updateColor();


}

void GraphicPion::updateColor()
{
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
    this->setPixmap(img);
}
