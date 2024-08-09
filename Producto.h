#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <QString>

class Producto {
public:
    Producto(const QString& nombre, double precio);

    virtual QString getDetalles() const = 0;

    QString getNombre() const;
    double getPrecio() const;

protected:
    QString nombre;
    double precio;
};

#endif // PRODUCTO_H
