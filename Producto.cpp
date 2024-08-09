#include "Producto.h"

Producto::Producto(const QString& nombre, double precio)
    : nombre(nombre), precio(precio) {}

QString Producto::getNombre() const {
    return nombre;
}

double Producto::getPrecio() const {
    return precio;
}
