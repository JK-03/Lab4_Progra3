#ifndef FIGURA_H
#define FIGURA_H

#include <QPainter>

class Figura
{
public:
    virtual ~Figura() {}
    virtual void dibujar(QPainter *painter) const = 0; // Método virtual puro para dibujar la figura
};

#endif // FIGURA_H
