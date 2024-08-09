#ifndef ROPA_H
#define ROPA_H

#include "Producto.h"

class Ropa : public Producto {
public:
    Ropa(const QString& nombre, double precio, const QString& talla, const QString& material);

    QString getDetalles() const override;

private:
    QString talla;
    QString material;
};

#endif // ROPA_H
