#ifndef GRAPHICPIONINPUT_H
#define GRAPHICPIONINPUT_H

#include <QPushButton>

class GraphicPionInput : public QPushButton
{
    Q_OBJECT
    private:
    int codeCouleur;
    int couleurMax;

    public:
    GraphicPionInput();
    void updateColor();
    void setCodeCouleur(int code);
    int getCodeCouleur();

    public slots:
    void incrementCodeCouleur();


};

#endif // GRAPHICPIONINPUT_H
