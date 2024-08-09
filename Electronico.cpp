#include "Electronico.h"

Electronico::Electronico(const QString& nombre, double precio, const QString& marca, int garantia)
    : Producto(nombre, precio), marca(marca), garantia(garantia) {}

QString Electronico::getDetalles() const {
    return QString("Marca: %1, Garantía: %2 años").arg(marca).arg(garantia);
}
