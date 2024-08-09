#include "Triangulo.h"
#include <QPainter>

void Triangulo::dibujar(QPainter *painter) const
{
    painter->drawPolygon(polygon);
}
