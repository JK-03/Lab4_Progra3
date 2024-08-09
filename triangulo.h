#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Figura.h"
#include <QPolygon>

class Triangulo : public Figura
{
public:
    Triangulo(const QPolygon &polygon) : polygon(polygon) {}
    void dibujar(QPainter *painter) const override; // Sobrescribir el método con la firma correcta

private:
    QPolygon polygon;
};

#endif // TRIANGULO_H
