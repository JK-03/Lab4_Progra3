#ifndef CIRCULO_H
#define CIRCULO_H

#include "Figura.h"
#include <QPoint>

class Circulo : public Figura
{
public:
    Circulo(const QPoint &centro, int radio) : centro(centro), radio(radio) {}
    void dibujar(QPainter *painter) const override; // Sobrescribir el método con la firma correcta

private:
    QPoint centro;
    int radio;
};

#endif // CIRCULO_H
