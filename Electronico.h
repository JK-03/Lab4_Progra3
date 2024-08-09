#ifndef ELECTRONICO_H
#define ELECTRONICO_H

#include "Producto.h"

class Electronico : public Producto {
public:
    Electronico(const QString& nombre, double precio, const QString& marca, int garantia);

    QString getDetalles() const override;

private:
    QString marca;
    int garantia;
};

#endif // ELECTRONICO_H
