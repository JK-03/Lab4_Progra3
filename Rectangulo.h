#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Figura.h"
#include <QRect>

class Rectangulo : public Figura
{
public:
    Rectangulo(const QRect &rect) : rect(rect) {}
    void dibujar(QPainter *painter) const override; // Sobrescribir el método con la firma correcta

private:
    QRect rect;
};

#endif // RECTANGULO_H
