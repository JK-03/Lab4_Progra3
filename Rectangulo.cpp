#include "Rectangulo.h"
#include <QPainter>

void Rectangulo::dibujar(QPainter *painter) const
{
    painter->drawRect(rect);
}
