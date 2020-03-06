#ifndef GRAPHICPION_H
#define GRAPHICPION_H
#include <QLabel>

class GraphicPion : public QLabel
{
    private:
    int codeCouleur;


    public:
    GraphicPion();
    GraphicPion(int code);
    void updateColor();
    void assignColor(int code);

};

#endif // GRAPHICPION_H
